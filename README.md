# Multithreaded Theater Seat Booking Simulation

## Overview

This program simulates a multithreaded theater seat booking system. Multiple customers attempt to book seats in a theater with a fixed number of aisles and seats per aisle. The system ensures thread-safe access to seats using mutex locks, avoiding conflicts during simultaneous booking attempts.

## Features

- **Multithreading**: Each customer booking process is handled in a separate thread.
- **Thread-Safe Seat Management**: Mutex locks prevent race conditions while booking seats.
- **Configurable Input**: The program reads customer booking attempts from a text file.
- **Logging**: Logs successful and failed booking attempts for each customer.
- **Final Seat Layout**: Displays the theater’s final seating arrangement after all bookings.

---

## How to Compile

Use the following command to compile the program using `gcc`:

```sh
gcc -o main main.c
```

## How to Run

Run the program by providing an input file containing booking requests:

```sh
./main <input_file>
```

For example:

```sh
./main bookings.txt
```

## Input File Format

The input file should contain booking requests in the following format:

```
Customer ID, Aisle, Seat, Aisle, Seat, Aisle, Seat, Aisle, Seat
<customer_id, aisle_number, seat_number, aisle_number, seat_number, ...>
<customer_id, aisle_number, seat_number, aisle_number, seat_number, ...>
```

- Each line represents a customer's booking attempt.
- A customer can request multiple seats in one attempt.
- Multiple attempts for the same customer can appear on different lines.

Example input:

```
Customer ID, Aisle, Seat, Aisle, Seat, Aisle, Seat, Aisle, Seat
101, 3, 5, 3, 6, 3, 7, 3, 8  # Center seats in the middle aisle
102, 3, 7, 3, 8  # Conflict with Customer 101
102, 3, 3, 3, 4  # Successful re-booking for Customer 102
103, 2, 5, 2, 6, 2, 7, 2, 8  # Center seats in the upper-middle aisle
104, 4, 5, 4, 6, 4, 7, 4, 8  # Center seats in the lower-middle aisle
105, 2, 3, 2, 4
106, 2, 7, 2, 8  # Conflict with Customer 103
106, 2, 9, 2, 10 # Successful re-booking for Customer 106
107, 4, 3, 4, 4
108, 4, 5, 4, 6  # Conflict with Customer 104
108, 4, 9, 4, 10 # Successful re-booking for Customer 108
109, 3, 9, 3, 10
110, 1, 5, 1, 6, 1, 7, 1, 8  # Center seats in aisle 1
111, 5, 5, 5, 6, 5, 7, 5, 8  # Center seats in aisle 5
112, 1, 3, 1, 4
113, 1, 7, 1, 8  # Conflict with Customer 110
113, 1, 9, 1, 10 # Successful re-booking for Customer 113
114, 5, 3, 5, 4
115, 5, 7, 5, 8  # Conflict with Customer 111
115, 5, 9, 5, 10 # Successful re-booking for Customer 115
```

## Output Format

The program prints messages indicating successful or failed booking attempts:

```
Customer 1 - Successful - Aisle 1, Seat 5, Aisle 2, Seat 3
Customer 2 - Fail - Aisle 3, Seat 6
Customer 3 - Successful - Aisle 1, Seat 1, Aisle 1, Seat 2, Aisle 1, Seat 3
Customer 4 - Successful - Aisle 5, Seat 10
```

## Implementation Details

- **Mutex Locks**: Each seat has an associated mutex to prevent race conditions.
- **Random Sleep**: Simulates real-world delays in booking processes.
- **Thread Synchronization**: Ensures correct output logging by using a global print mutex.

## Possible Enhancements

- Allow dynamic theater sizes.
- Implement a retry mechanism for failed bookings.
- Optimize thread scheduling for better efficiency.
