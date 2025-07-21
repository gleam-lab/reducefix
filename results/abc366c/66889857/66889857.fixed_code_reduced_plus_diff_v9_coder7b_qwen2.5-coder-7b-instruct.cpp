#include <iostream>
#include <unordered_set>

int main() {
    int n;
    std::cin >> n;
    std::unordered_set<int> bag;

    for (int i = 0; i < n; ++i) {
        int op, x;
        std::cin >> op >> x;

        if (op == 1) {
            // Insert element x into the bag
            bag.insert(x);
        } else if (op == 2) {
            // Erase element x from the bag if it exists
            auto it = bag.find(x);
            if (it != bag.end()) {
                bag.erase(it);
            }
        } else if (op == 3) {
            // Print the number of distinct elements in the bag
            std::cout << bag.size() << std::endl;
        }
    }

    return 0;
}