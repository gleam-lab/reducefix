#include <iostream>
#include <set>

int main() {
    int Q;
    std::cin >> Q;
    
    std::set<int> balls;
    
    for (int q = 0; q < Q; ++q) {
        int type;
        std::cin >> type;
        
        if (type == 1) {
            int value;
            std::cin >> value;
            balls.insert(value);
        } else if (type == 2) {
            int value;
            std::cin >> value;
            balls.erase(value);
        } else if (type == 3) {
            std::cout << balls.size() << std::endl;
        }
    }
    
    return 0;
}