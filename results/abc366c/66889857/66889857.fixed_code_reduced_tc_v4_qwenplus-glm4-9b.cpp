#include <iostream>
#include <set>

int main() {
    int Q;
    std::cin >> Q;
    std::set<int> balls;
    
    for (int i = 0; i < Q; ++i) {
        int query;
        std::cin >> query;
        if (query == 1) {
            int ball;
            std::cin >> ball;
            balls.insert(ball);
        } else if (query == 2) {
            int ball;
            std::cin >> ball;
            balls.erase(ball);
        } else if (query == 3) {
            std::cout << balls.size() << std::endl;
        }
    }

    return 0;
}