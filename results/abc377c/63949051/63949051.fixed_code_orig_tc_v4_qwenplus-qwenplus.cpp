// C++20 required

#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// Using 64-bit or better integers
using i128 = long long;

// Custom hash for pair<int, int>
struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return ((size_t)(p.first) << 32) | (unsigned int)p.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int M;
    cin >> N >> M;

    unordered_set<pair<int, int>, PairHash> forbidden;

    vector<pair<int, int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int m = 0; m < M; ++m) {
        int a, b;
        cin >> a >> b;

        // Add current piece position
        forbidden.emplace(a, b);

        // Add all possible attacked positions
        for (auto [dx, dy] : directions) {
            int na = a + dx;
            int nb = b + dy;
            if (1 <= na && na <= N && 1 <= nb && nb <= N) {
                forbidden.emplace(na, nb);
            }
        }
    }

    // Total cells: N*N
    i128 total_cells = (i128)N * N;

    // Forbidden cells = occupied + attacked positions (without duplicates)
    i128 answer = total_cells - (i128)forbidden.size();

    cout << answer << endl;

    return 0;
}