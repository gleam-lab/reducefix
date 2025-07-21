#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> a(N), b(N - 1);
    
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < N - 1; i++) {
        std::cin >> b[i];
    }

    std::sort(a.begin(), a.end(), std::greater<int>());
    std::sort(b.begin(), b.end(), std::greater<int>());

    int min_x = -1;
    for (int i = 0; i < N; i++) {
        if (i == 0 || a[i] <= a[i - 1]) {
            for (int j = 0; j < N - 1; j++) {
                if (a[i] <= b[j]) {
                    min_x = b[j];
                    break;
                }
            }
        }
        if (min_x == -1) {
            break;
        }
    }

    if (min_x != -1) {
        std::cout << min_x << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}