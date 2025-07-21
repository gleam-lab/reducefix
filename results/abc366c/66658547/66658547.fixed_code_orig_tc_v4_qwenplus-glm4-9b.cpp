#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> bag;
    int q;
    std::cin >> q;

    while (q--) {
        int command;
        std::cin >> command;

        if (command == 1) {
            int x;
            std::cin >> x;
            bag.insert(x);
        } else if (command == 2) {
            int x;
            std::cin >> x;
            bag.erase(x);
        } else if (command == 3) {
            std::cout << bag.size() << "\n";
        }
    }

    return 0;
}