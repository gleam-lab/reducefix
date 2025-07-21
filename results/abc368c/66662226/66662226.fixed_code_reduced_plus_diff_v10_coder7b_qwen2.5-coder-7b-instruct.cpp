#include <iostream>
#include <vector>

int main() {
    unsigned long long n;
    std::cin >> n;
    std::vector<unsigned long long> h(n);
    for(unsigned long long &x : h) {
        std::cin >> x;
    }

    unsigned long long t = 0;
    bool front = true;
    for(unsigned long long &x : h) {
        if(x == 0) continue;
        if(front) {
            x--;
            front = false;
        } else {
            x -= x % 3 + 1;
            front = true;
        }
        t++;
    }

    std::cout << t << std::endl;
    return 0;
}