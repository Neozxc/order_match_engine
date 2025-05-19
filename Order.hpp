#ifndef ORDER_HPP
#define ORDER_HPP

#include <cstdint>
#include <string>
#include <chrono>

enum class OrderType
{
    BUY,
    SELL
};

struct alignas(64) Order
{
    uint64_t id;
    OrderType type;
    double price;
    uint32_t quantity;
    std::chrono::high_resolution_clock::time_point timestamp;

    Order(uint64_t id_, OrderType type_, double price_, uint32_t quantity_) : id(id_), type(type_), price(price_), quantity(quantity_), timestamp(std::chrono::high_resolution_clock::now()) {};
};
