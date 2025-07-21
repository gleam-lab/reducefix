#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    set<pair<int, int>> forbidden;
    set<pair<int, int>> pieces;
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        pieces.insert({a, b});
    }
    
    for (auto [a, b] : pieces) {
        for (int dx : {-2, -1, 1, 2}) {
            for (int dy : {-2, -1, 1, 2}) {
                if (abs(dx) + abs(dy) != 3) continue;
                int x = a + dx;
                int y = b + dy;
                if (x >= 1 && x <= N && y >= 1 && y <= N) {
                    forbidden.insert({x, y});
                }
            }
        }
    }
    
    int total_empty = N * N - pieces.size();
    int safe_empty = total_empty - (forbidden.size() - count_if(forbidden.begin(), forbidden.end(), 
        [&](const pair<int, int>& p) { return pieces.count(p); }));
    
    cout << safe_empty << '\n';
    
    return 0;
}