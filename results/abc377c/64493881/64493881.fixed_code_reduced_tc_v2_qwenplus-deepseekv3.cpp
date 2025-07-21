#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int64_t N, M;
    cin >> N >> M;
    
    set<pair<int64_t, int64_t>> unsafe;
    vector<pair<int64_t, int64_t>> pieces(M);
    
    for (int i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        unsafe.insert({a, b});
    }
    
    const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    
    for (auto [a, b] : pieces) {
        for (int k = 0; k < 8; ++k) {
            int64_t x = a + dx[k];
            int64_t y = b + dy[k];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                unsafe.insert({x, y});
            }
        }
    }
    
    cout << (N * N - unsafe.size()) << '\n';
    
    return 0;
}