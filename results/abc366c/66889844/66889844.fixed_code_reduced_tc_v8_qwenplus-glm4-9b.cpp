#include <iostream>
#include <set>

int main() {
    int Q;
    std::cin >> Q;

    std::set<int> a;
    
    for (int i = 0; i < Q; ++i) {
        int query;
        std::cin >> query;
        
        if (query == 1) {
            int x;
            std::cin >> x;
            a.insert(x);
        } else if (query == 2) {
            int x;
            std::cin >> x;
            a.erase(x);
        } else if (query == 3) {
            std::cout << a.size() << std::endl;
        }
    }

    return 0;
}