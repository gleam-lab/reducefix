#include <iostream>
#include <set>

int main() {
    std::set<int> s;
    int q;
    std::cin >> q;

    while (q--) {
        int n;
        std::cin >> n;
        if (n == 1) {
            int x;
            std::cin >> x;
            s.insert(x);
        } else if (n == 2) {
            int x;
            std::cin >> x;
            s.erase(x);
        } else {
            std::cout << s.size() << '\n';
        }
    }

    return 0;
}