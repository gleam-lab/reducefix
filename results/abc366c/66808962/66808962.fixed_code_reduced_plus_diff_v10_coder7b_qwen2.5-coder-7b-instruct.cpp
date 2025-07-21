#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> s;
    int q;
    std::cin >> q;
    
    while (q--) {
        int type, x;
        std::cin >> type;
        
        if (type == 1) {
            std::cin >> x;
            s.insert(x);
        } else if (type == 2) {
            std::cin >> x;
            s.erase(s.find(x));
        } else if (type == 3) {
            std::cout << s.size() << '\n';
        }
    }
    
    return 0;
}