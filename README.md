# Order Matching Engine (C++)

Simple limit order matching engine using price-time priority

## Structure

- `Order.hpp` – Defines the `Order` struct with timestamp and type.
- `OrderBook.hpp` / `OrderBook.cpp` – Implements order matching logic using priority queues.
- `main.cpp` – Basic test harness with hardcoded order scenarios.

## Build

```bash
g++ -std=c++17 -O2 main.cpp OrderBook.cpp -o match