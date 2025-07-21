#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    set<pair<int, int>> occupied;
    set<pair<int, int>> attacked;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        occupied.insert({a, b});

        // All 8 possible attack positions
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int k = 0; k < 8; ++k) {
            int ni = a + dx[k];
            int nj = b + dy[k];
            if (ni >= 1 && ni <= N && nj >= 1 && nj <= N) {
                attacked.insert({ni, nj});
            }
        }
    }

    // Total squares that are either occupied or attacked
    set<pair<int, int>> total;
    total.insert(occupied.begin(), occupied.end());
    total.insert(attacked.begin(), attacked.end());

    long long safe = N * N - total.size();
    cout << safe << '\n';

    return 0;
}