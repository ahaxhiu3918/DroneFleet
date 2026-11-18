# Dynamic Drone Fleet

A small C++ console program that manages a fleet of drones using dynamic memory allocation. The user chooses the fleet size at runtime, enters each drone's details, and the program stores them in a heap-allocated array of `Drone*`.

## Features

- Fleet size chosen by the user at runtime
- Dynamic allocation of an array of `Drone*` (`new Drone*[n]`)
- One `Drone` object allocated per entry (`new Drone(...)`)
- Proper cleanup: each drone is deleted first, then the array itself with `delete[]`

## Project Structure

```
.
├── Drone.h        # Drone class declaration
├── Drone.cpp      # Drone class implementation
├── main.cpp       # Program entry point (input, allocation, cleanup)
├── Makefile       # Build and run
└── README.md
```

## Build and Run

Requires a C++17 compiler.

```bash
make
./main
```

Key points:

- `std::array` cannot be used here because its size must be known at compile time, while the fleet size is only known at runtime.
- `delete[]` on the array alone does not free the drones it points to; the loop is required to avoid memory leaks.

## Possible Future Improvements

- Replace raw pointers with `std::vector<std::unique_ptr<Drone>>` so cleanup is automatic
- Validate user input (negative fleet size, non-numeric battery values)
- Add features to list, search, or remove drones
- Add feature(s) to modify the drone's battery lifetime at runtime