# Cab Booking System - Low-Level Design (LLD)

[Warning: This readme.md was generated using ChatGPT]

A C++ implementation of a cab booking platform's core components, demonstrating object-oriented design principles and strategy patterns.

## 📁 Project Structure

- `driver.h` / `driver.cpp`: Represents the Driver entity.
- `rider.h` / `rider.cpp`: Represents the Rider entity.
- `trip.h` / `trip.cpp`: Manages Trip details.
- `tripManager.h` / `tripManager.cpp`: Singleton class to manage all trips.
- `tripMetaData.h` / `tripMetaData.cpp`: Stores metadata related to trips.
- `driverManager.h` / `driverManager.cpp`: Manages driver-related operations.
- `riderManager.h` / `riderManager.cpp`: Manages rider-related operations.
- `PricingStrategy/`: Contains different pricing strategy implementations.
- `DriverMatchStrategy/`: Contains driver matching strategy implementations.
- `utilities.h`: Contains utility enums and constants.
- `uber.cpp`: Entry point demonstrating the system's functionality.

## 🚀 Features

- **Modular Design**: Each component is encapsulated in its own class.
- **Strategy Pattern**: Easily switch between different pricing and driver matching strategies.
- **Singleton Pattern**: Ensures a single instance of `TripManager` manages all trips.
- **Scalability**: Designed to accommodate additional features like payment processing, ratings, and more.

## 🔧 Build & Run

### Prerequisites

- C++17 compatible compiler (e.g., g++, clang++)
- CMake (optional, for build automation)

### Using g++

