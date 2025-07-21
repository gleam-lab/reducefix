#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, int> bag;
    int Q;
    std::cin >> Q;
    
    for (int i = 0; i < Q; i++) {
        int type;
        std::cin >> type;
        
        if (type == 1) {
            int x;
            std::cin >> x;
            bag[x]++;
        } else if (type == 2) {
            int x;
            std::cin >> x;
            bag[x]--;
        } else if (type == 3) {
            std::cout << bag.size() << std::endl;
        }
    }
    
    return 0;
}