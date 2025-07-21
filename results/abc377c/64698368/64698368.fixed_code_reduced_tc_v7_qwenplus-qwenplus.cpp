#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    int M;
    cin >> N >> M;

    // Use a hash set for O(1) average time complexity for insertions and lookups
    unordered_set<ll> attacked;
    
    // Directions from the problem statement
    array<array<ll, 2>, 9> dir = {
        array<ll, 2>{0, 0},
        array<ll, 2>{2, 1},
        array<ll, 2>{1, 2},
        array<ll, 2>{-1, 2},
        array<ll, 2>{-2, 1},
        array<ll, 2>{-2, -1},
        array<ll, 2>{-1, -2},
        array<ll, 2>{1, -2},
        array<ll, 2>{2, -1}
    };

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;

        // For each piece, mark all reachable attack positions
        for (const auto& [dx, dy] : dir) {
            ll x = a + dx;
            ll y = b + dy;

            // Only mark positions that are within the board
            if (1 <= x && x <= N && 1 <= y && y <= N) {
                // Map 2D coordinate to a unique 1D key using perfect hashing
                // Since 1 <= x,y <= N, we can use: key = x * N + y
                attacked.insert(x * N + y);
            }
        }
    }

    // Total number of cells is N^2
    // Subtract the number of attacked positions
    cout << N * N - (ll)attacked.size() << endl;

    return 0;
}