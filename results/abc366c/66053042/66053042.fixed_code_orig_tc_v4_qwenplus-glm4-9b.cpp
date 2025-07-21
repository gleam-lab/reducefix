#include <iostream>
#include <map>

int main() {
    std::map<int, int> m;
    int Q, x;
    std::cin >> Q;

    while (Q--) {
        std::cin >> x;
        if (x == 1) { // Add ball
            int count = m[x]++;
            if (count == 1) { // Ball added for the first time
                std::cout << ++m.size() << std::endl; // Update number of distinct balls
            }
        } else if (x == 2) { // Remove ball
            int count = m[x]--;
            if (count == 0) { // Ball removed completely from the bag
                std::cout << --m.size() << std::endl; // Update number of distinct balls
            }
        } else if (x == 3) { // Count distinct balls
            std::cout << m.size() << std::endl;
        }
    }

    return 0;
}