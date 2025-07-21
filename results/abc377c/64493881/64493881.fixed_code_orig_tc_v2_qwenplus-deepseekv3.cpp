#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int64_t N, M;
    cin >> N >> M;
    
    set<pair<int64_t, int64_t>> pieces;
    set<pair<int64_t, int64_t>> unsafe;
    
    for (int i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        unsafe.insert({a, b});
        
        vector<pair<int64_t, int64_t>> moves = {
            {a + 2, b + 1}, {a + 1, b + 2},
            {a - 1, b + 2}, {a - 2, b + 1},
            {a - 2, b - 1}, {a - 1, b - 2},
            {a + 1, b - 2}, {a + 2, b - 1}
        };
        
        for (auto [x, y] : moves) {
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                unsafe.insert({x, y});
            }
        }
    }
    
    cout << N * N - unsafe.size() << '\n';
    
    return 0;
}