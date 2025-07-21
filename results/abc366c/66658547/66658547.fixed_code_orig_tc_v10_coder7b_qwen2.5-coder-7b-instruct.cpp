#include <iostream>
#include <set>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::unordered_map<int, bool> bag;
    std::set<int> unique_elements;

    int q;
    std::cin >> q;

    while (q--) {
        int x;
        std::cin >> x;

        if (x == 1) {
            int t;
            std::cin >> t;
            if (!bag[t]) {
                unique_elements.insert(t);
            }
            bag[t] = true;
        } else if (x == 2) {
            int t;
            std::cin >> t;
            if (bag[t]) {
                unique_elements.erase(unique_elements.find(t));
                bag[t] = false;
            }
        } else {
            std::cout << unique_elements.size() << '\n';
        }
    }

    return 0;
}