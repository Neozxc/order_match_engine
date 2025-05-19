#include "OrderBook.hpp"

void OrderBook::addOrder(const Order &order)
{
    Order incoming = order;

    if (order.type == OrderType::BUY)
    {
        while (!sellOrders.empty() &&
               incoming.price >= sellOrders.top().price &&
               incoming.quantity > 0)
        {
            Order bestSell = sellOrders.top();
            sellOrders.pop();

            uint32_t tradeQty = std::min(incoming.quantity, bestSell.quantity);
            trades.push_back({incoming.id,
                              bestSell.id,
                              bestSell.price,
                              tradeQty});

            incoming.quantity -= tradeQty;
            bestSell.quantity -= tradeQty;

            if (bestSell.quantity > 0)
            {
                sellOrders.push(bestSell);
            }
        }

        if (incoming.quantity > 0)
        {
            buyOrders.push(incoming);
        }
    }
    else if (order.type == OrderType::SELL)
    {
        while (!buyOrders.empty() &&
               incoming.price <= buyOrders.top().price &&
               incoming.quantity > 0)
        {
            Order bestBuy = buyOrders.top();
            buyOrders.pop();

            uint32_t tradeQty = std::min(incoming.quantity, bestBuy.quantity);
            trades.push_back({bestBuy.id,
                              incoming.id,
                              bestBuy.price,
                              tradeQty});

            incoming.quantity -= tradeQty;
            bestBuy.quantity -= tradeQty;

            if (bestBuy.quantity > 0)
            {
                buyOrders.push(bestBuy);
            }
        }

        if (incoming.quantity > 0)
        {
            sellOrders.push(incoming);
        }
    }
}

void OrderBook::printTrades() const
{
    std::cout << "Matched Trades:\n";
    for (const auto &trade : trades)
    {
        std::cout << "BUY #" << trade.buyOrderId
                  << " ⟷ SELL #" << trade.sellOrderId
                  << " @ " << trade.price
                  << " x " << trade.quantity << '\n';
    }
}
