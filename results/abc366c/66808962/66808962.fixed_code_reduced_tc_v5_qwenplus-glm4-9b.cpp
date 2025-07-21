#include <iostream>
#include <unordered_map>

int main() {
    int q;
    std::cin >> q;

    std::unordered_map<int, int> balls;
    int ans = 0;

    for (int i = 0; i < q; i++) {
        int n;
        std::cin >> n;

        if (n == 1) {
            int x;
            std::cin >> x;
            if (balls[x] == 0) {
                ans++;
            }
            balls[x]++;
        } else if (n == 2) {
            int x;
            std::cin >> x;
            balls[x]--;
            if (balls[x] == 0) {
                ans--;
            }
        } else if (n == 3) {
            std::cout << ans << std::endl;
        }
    }

    return 0;
}