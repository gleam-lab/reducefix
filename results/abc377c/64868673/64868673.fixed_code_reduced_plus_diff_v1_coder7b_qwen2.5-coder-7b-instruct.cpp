#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>

int main() {
    long long n, m;
    std::cin >> n >> m;

    std::unordered_set<std::pair<long long, long long>> occupied;
    for(long long i = 0; i < m; ++i) {
        long long a, b;
        std::cin >> a >> b;
        occupied.insert({a, b});
    }

    long long count = 0;
    for(long long i = 1; i <= n; ++i) {
        for(long long j = 1; j <= n; ++j) {
            bool can_place = true;
            for(long long di = -2; di <= 2; ++di) {
                for(long long dj = -2; dj <= 2; ++dj) {
                    if(abs(di) + abs(dj) == 3 && 
                       i + di >= 1 && i + di <= n && 
                       j + dj >= 1 && j + dj <= n) {
                        if(occupied.find({i + di, j + dj}) != occupied.end()) {
                            can_place = false;
                            break;
                        }
                    }
                }
                if(!can_place) break;
            }
            if(can_place) count++;
        }
    }

    std::cout << n * n - count << '\n';
    return 0;
}