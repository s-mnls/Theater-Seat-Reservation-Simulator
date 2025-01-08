#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>    // For sleep()
#include <ctype.h>     // For isspace()
#include <time.h>      // For time(), srand(), rand()

#define NUM_AISLES 5
#define NUM_SEATS_PER_AISLE 12
#define MAX_CUSTOMERS 50
#define MAX_ATTEMPTS_PER_CUSTOMER 10
#define MAX_SEATS_PER_ATTEMPT 60
#define MAX_LINE_LENGTH 1024

int seats[NUM_AISLES][NUM_SEATS_PER_AISLE];
pthread_mutex_t seat_mutexes[NUM_AISLES][NUM_SEATS_PER_AISLE];
pthread_mutex_t print_mutex = PTHREAD_MUTEX_INITIALIZER; // For synchronized printing

typedef struct {
    int customer_id;
    int num_seats;
    int aisle_numbers[MAX_SEATS_PER_ATTEMPT];
    int seat_numbers[MAX_SEATS_PER_ATTEMPT];
} BookingAttempt;

typedef struct {
    int customer_id;
    int num_attempts;
    BookingAttempt attempts[MAX_ATTEMPTS_PER_CUSTOMER];
} Customer;

void *customer_thread(void *arg) {
    Customer *cust = (Customer *)arg;

    for (int attempt_idx = 0; attempt_idx < cust->num_attempts; attempt_idx++) {
        BookingAttempt *attempt = &cust->attempts[attempt_idx];
        int locks_acquired = 0;
        pthread_mutex_t *acquired_mutexes[MAX_SEATS_PER_ATTEMPT];
        int success = 1;

        // Attempt to lock all requested seats
        for (int i = 0; i < attempt->num_seats; i++) {
            int aisle = attempt->aisle_numbers[i] - 1; // Zero-based indexing
            int seat = attempt->seat_numbers[i] - 1;   // Zero-based indexing

            if (aisle < 0 || aisle >= NUM_AISLES || seat < 0 || seat >= NUM_SEATS_PER_AISLE) {
                success = 0;
                break;
            }

            if (pthread_mutex_trylock(&seat_mutexes[aisle][seat]) == 0) {
                acquired_mutexes[locks_acquired++] = &seat_mutexes[aisle][seat];
                if (seats[aisle][seat] != 0) {
                    success = 0;
                    break;
                }
            } else {
                success = 0;
                break;
            }
        }

        if (!success) {
            // Release any locks held
            for (int i = 0; i < locks_acquired; i++) {
                pthread_mutex_unlock(acquired_mutexes[i]);
            }

            // Log failure
            pthread_mutex_lock(&print_mutex);
            printf("Customer %d - Fail - ", cust->customer_id);
            for (int i = 0; i < attempt->num_seats; i++) {
                printf("Aisle %d, Seat %d", attempt->aisle_numbers[i], attempt->seat_numbers[i]);
                if (i != attempt->num_seats - 1) printf(", ");
            }
            printf("\n");
            pthread_mutex_unlock(&print_mutex);

            continue; // Proceed to the next attempt
        }

        // Simulate customer activity
        int sleep_time = (rand() % 3) + 1; // Random number between 1 and 3
        sleep(sleep_time);

        // Assign seats to the customer
        for (int i = 0; i < attempt->num_seats; i++) {
            int aisle = attempt->aisle_numbers[i] - 1;
            int seat = attempt->seat_numbers[i] - 1;
            seats[aisle][seat] = cust->customer_id;
        }

        // Release all locks
        for (int i = 0; i < locks_acquired; i++) {
            pthread_mutex_unlock(acquired_mutexes[i]);
        }

        // Log success
        pthread_mutex_lock(&print_mutex);
        printf("Customer %d - Successful - ", cust->customer_id);
        for (int i = 0; i < attempt->num_seats; i++) {
            printf("Aisle %d, Seat %d", attempt->aisle_numbers[i], attempt->seat_numbers[i]);
            if (i != attempt->num_seats - 1) printf(", ");
        }
        printf("\n");
        pthread_mutex_unlock(&print_mutex);
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./assignment-5 <input_file>\n");
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];

    // Initialize seats array and mutexes
    for (int i = 0; i < NUM_AISLES; i++) {
        for (int j = 0; j < NUM_SEATS_PER_AISLE; j++) {
            seats[i][j] = 0; // 0 indicates unbooked seats
            pthread_mutex_init(&seat_mutexes[i][j], NULL);
        }
    }

    // Initialize random number generator
    srand(time(NULL));

    // Open the input file
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read and parse the input file
    Customer customers[MAX_CUSTOMERS];
    int num_customers = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), fp)) {
        if (line[0] == '\n' || line[0] == '\r') continue; // Skip empty lines

        // Remove newline characters
        char *newline = strchr(line, '\n');
        if (newline) *newline = '\0';

        // Remove comments
        char *comment = strchr(line, '#');
        if (comment) *comment = '\0';

        // Trim leading whitespace
        char *ptr = line;
        while (isspace(*ptr)) ptr++;
        if (*ptr == '\0') continue; // Skip if line is empty after trimming

        // Check if line is a header or invalid
        if (!isdigit(*ptr)) continue; // Skip non-data lines

        // Parse customer ID
        char *token = strtok(ptr, ", ");
        if (!token) continue;
        char *endptr;
        int customer_id = strtol(token, &endptr, 10);
        if (*endptr != '\0') continue; // Invalid customer ID, skip line

        // Parse seat requests
        int aisle_numbers[MAX_SEATS_PER_ATTEMPT];
        int seat_numbers[MAX_SEATS_PER_ATTEMPT];
        int num_seats = 0;

        while ((token = strtok(NULL, ", ")) != NULL) {
            // Parse aisle number
            int aisle = strtol(token, &endptr, 10);
            if (*endptr != '\0') break; // Invalid aisle number
            token = strtok(NULL, ", ");
            if (!token) break;
            // Parse seat number
            int seat = strtol(token, &endptr, 10);
            if (*endptr != '\0') break; // Invalid seat number
            aisle_numbers[num_seats] = aisle;
            seat_numbers[num_seats] = seat;
            num_seats++;
        }

        if (num_seats == 0) continue;

        // Find or create customer
        int customer_index = -1;
        for (int i = 0; i < num_customers; i++) {
            if (customers[i].customer_id == customer_id) {
                customer_index = i;
                break;
            }
        }

        if (customer_index == -1) {
            if (num_customers >= MAX_CUSTOMERS) {
                fprintf(stderr, "Maximum number of customers exceeded\n");
                exit(EXIT_FAILURE);
            }
            customer_index = num_customers++;
            customers[customer_index].customer_id = customer_id;
            customers[customer_index].num_attempts = 0;
        }

        // Add booking attempt
        Customer *cust = &customers[customer_index];
        if (cust->num_attempts >= MAX_ATTEMPTS_PER_CUSTOMER) {
            fprintf(stderr, "Maximum attempts per customer exceeded\n");
            exit(EXIT_FAILURE);
        }
        BookingAttempt *attempt = &cust->attempts[cust->num_attempts++];
        attempt->customer_id = customer_id;
        attempt->num_seats = num_seats;
        for (int i = 0; i < num_seats; i++) {
            attempt->aisle_numbers[i] = aisle_numbers[i];
            attempt->seat_numbers[i] = seat_numbers[i];
        }
    }

    fclose(fp);

    // Create threads for each customer
    pthread_t threads[MAX_CUSTOMERS];
    for (int i = 0; i < num_customers; i++) {
        int ret = pthread_create(&threads[i], NULL, customer_thread, (void *)&customers[i]);
        if (ret != 0) {
            fprintf(stderr, "Error creating thread for customer %d\n", customers[i].customer_id);
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < num_customers; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("\n");

    // Print final theater layout
    printf("          ");
    for (int i = 1; i <= NUM_SEATS_PER_AISLE; i++) {
        printf("%-4d", i);
    }

    printf("\n");
    for (int i = 0; i < NUM_AISLES; i++) {
        printf("Aisle %-2d  ", i + 1);
        for (int j = 0; j < NUM_SEATS_PER_AISLE; j++) {
            printf("%-4.3d", seats[i][j]);
        }
        printf("\n");
    }

    // Destroy mutexes
    for (int i = 0; i < NUM_AISLES; i++) {
        for (int j = 0; j < NUM_SEATS_PER_AISLE; j++) {
            pthread_mutex_destroy(&seat_mutexes[i][j]);
        }
    }

    return 0;
}
