#ifndef ORDERBOOK_HPP
#define ORDERBOOK_HPP

#include "Order.hpp"
#include <queue>
#include <vector>
#include <functional>
#include <iostream>

struct Trade
{
    uint64_t buyOrderId;
    uint64_t sellOrderId;
    double price;
    uint32_t quantity;
};

struct BuyOrderCompare
{
    bool operator()(const Order &a, const Order &b) const
    {
        if (a.price == b.price)
        {
            return a.timestamp > b.timestamp;
        }

        return a.price < b.price;
    }
};

struct SellOrderCompare
{
    bool operator()(const Order &a, const Order &b) const
    {
        if (a.price == b.price)
        {
            return a.timestamp > b.timestamp;
        }

        return a.price > b.price;
    }
};

class OrderBook
{

private:
    std::priority_queue<Order, std::vector<Order>, BuyOrderCompare> buyOrders;
    std::priority_queue<Order, std::vector<Order>, SellOrderCompare> sellOrders;
    std::vector<Trade> trades;

public:
    void addOrder(const Order &order);
    const std::vector<Trade> &getTrades() const { return trades; }
};

#endif
