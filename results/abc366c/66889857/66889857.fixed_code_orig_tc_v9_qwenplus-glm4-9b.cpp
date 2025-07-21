#include <iostream>
#include <set>
#include <vector>

int main() {
    int q;
    std::cin >> q;

    std::set<int> balls;
    std::vector<int> results;

    for (int i = 0; i < q; ++i) {
        int t;
        std::cin >> t;

        if (t == 1) {
            int x;
            std::cin >> x;
            balls.insert(x);
        } else if (t == 2) {
            int x;
            std::cin >> x;
            balls.erase(x);
        } else if (t == 3) {
            results.push_back(balls.size());
        }
    }

    for (int result : results) {
        std::cout << result << std::endl;
    }

    return 0;
}