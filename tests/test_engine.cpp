#include <gtest/gtest.h>
#include <vector>
#include <string>

// Simple Trading Engine Logic
enum class OrderStatus { ACCEPTED, REJECTED };

struct Order {
    int id;
    double price;
    int quantity;
};

class TradingEngine {
public:
    OrderStatus processOrder(const Order& order) {
        if (order.price <= 0 || order.quantity <= 0) {
            return OrderStatus::REJECTED;
        }
        return OrderStatus::ACCEPTED;
    }
};

// --- TEST CASES FOR RENE ---

// 1. Resilience Test: Handling bad data
TEST(TradingEngineTest, RejectsInvalidPrices) {
    TradingEngine engine;
    Order badOrder{1, -50.5, 100}; 
    ASSERT_EQ(engine.processOrder(badOrder), OrderStatus::REJECTED);
}

// 2. Performance/Latency Test: Batch processing
TEST(TradingEngineTest, HandlesHighVolumeLoad) {
    TradingEngine engine;
    for (int i = 0; i < 10000; ++i) {
        Order o{i, 150.0, 10};
        ASSERT_EQ(engine.processOrder(o), OrderStatus::ACCEPTED);
    }
}
