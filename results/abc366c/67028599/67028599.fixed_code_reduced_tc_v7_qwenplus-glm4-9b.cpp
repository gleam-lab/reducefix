#include <iostream>
#include <set>

int main() {
    int q;
    std::cin >> q;

    std::set<int> bag;
    int type, x;
    while (q--) {
        std::cin >> type;
        if (type == 1) {
            std::cin >> x;
            bag.insert(x);
        } else if (type == 2) {
            std::cin >> x;
            bag.erase(x);
        } else {
            std::cout << bag.size() << std::endl;
        }
    }

    return 0;
}