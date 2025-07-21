#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    unordered_set<int> threats;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b; // Convert to zero-based indexing

        // Mark row threats
        threats.insert(a * N + b);
        // Mark column threats
        threats.insert(a * N + b);
        // Mark diagonal threats
        threats.insert((a + b) * N + b);
        threats.insert((a - b + N) * N + b); // To handle negative indices
    }

    i64 empty_squares = N * N - threats.size();
    cout << empty_squares << '\n';

    return 0;
}