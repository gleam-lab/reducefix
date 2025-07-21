#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;

    set<pair<int, int>> st;
    vector<pair<int, int>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--; // Convert to 0-based index
        for (auto [dx, dy] : moves) {
            int x = a + dx;
            int y = b + dy;
            if (x >= 0 && x < N && y >= 0 && y < N) {
                st.insert({x, y});
            }
        }
    }

    ll total = (ll)N * N;
    ll forbidden = st.size();
    cout << total - forbidden - M << endl;
    return 0;
}