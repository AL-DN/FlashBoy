// Author: Alden Sahi
// Date: 07.27.2026
// Program Name: OrderPriorityQueue.h
/* Program Description: 
    Accepts, Persists and Sorts Orders based on arrival time
    Pops from top when current time >= arrival time of top element
*/
#include "Order.h"

class OrderPriorityQueue {
    private:
        // Priority Comparator ( Used to Sort Queue)

        struct EventCompare {
            bool operator()(const Order& a, const Order& b) const {
                return a.arrival_time > b.arrival_time; // min-heap: earliest timestamp first
            }
        };

        // Builds Order Priority Queue

    public:
        OrderPriorityQueue();

};