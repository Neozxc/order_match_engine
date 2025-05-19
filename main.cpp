#include "Order.hpp"
#include "OrderBook.hpp"
#include <iostream>

int main()
{
    OrderBook book;

    book.addOrder(Order(1, OrderType::BUY, 100.0, 10));
    book.addOrder(Order(2, OrderType::SELL, 99.5, 5));
    book.addOrder(Order(3, OrderType::SELL, 99.0, 5));
    book.addOrder(Order(4, OrderType::SELL, 101.0, 10));
    book.addOrder(Order(5, OrderType::BUY, 102.0, 4));
    book.addOrder(Order(6, OrderType::SELL, 95.0, 8));

    book.printTrades();

    return 0;
}
