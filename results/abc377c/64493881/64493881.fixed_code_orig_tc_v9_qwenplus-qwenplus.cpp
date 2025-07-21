#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t N;
    int M;
    cin >> N >> M;

    unordered_set<int64_t> forbidden; // Using int64_t as key: (a << 32) | b

    vector<pair<int, int>> deltas = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;

        // Add current piece's position
        forbidden.insert(((int64_t)a << 32) | b);

        // Add all 8 threatened positions
        for (auto [da, db] : deltas) {
            int na = a + da;
            int nb = b + db;
            if (1 <= na && na <= N && 1 <= nb && nb <= N) {
                forbidden.insert(((int64_t)na << 32) | nb);
            }
        }
    }

    cout << (N * N - forbidden.size()) << endl;

    return 0;
}