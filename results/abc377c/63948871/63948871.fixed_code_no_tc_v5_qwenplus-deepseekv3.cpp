#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> occupied;
    set<pair<long long, long long>> unsafe;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});

        // Check all 8 possible attack positions
        vector<pair<long long, long long>> directions = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };

        for (const auto &dir : directions) {
            long long new_a = a + dir.first;
            long long new_b = b + dir.second;
            if (new_a >= 1 && new_a <= N && new_b >= 1 && new_b <= N) {
                unsafe.insert({new_a, new_b});
            }
        }
    }

    // Total safe squares = N^2 - (occupied squares + unsafe squares - squares that are both occupied and unsafe)
    // But since occupied squares are already in 'occupied' and no duplicates in 'unsafe', we can compute as:
    // Total safe squares = N * N - (occupied.size() + unsafe squares not in occupied)
    // To find the total unsafe squares (including occupied), we merge both sets
    for (const auto &p : occupied) {
        unsafe.insert(p);
    }

    long long total_safe = N * N - unsafe.size();
    cout << total_safe << "\n";

    return 0;
}