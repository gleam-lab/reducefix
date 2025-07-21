#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int N, M;
    cin >> N >> M;

    set<pair<int, int>> forbidden;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        forbidden.insert({a, b});

        // All 8 possible moves
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int k = 0; k < 8; ++k) {
            int new_a = a + dx[k];
            int new_b = b + dy[k];
            if (new_a >= 1 && new_a <= N && new_b >= 1 && new_b <= N) {
                forbidden.insert({new_a, new_b});
            }
        }
    }

    cout << N * N - forbidden.size() << endl;

    return 0;
}