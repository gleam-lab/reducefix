#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    set<pair<ll, ll>> knights;
    set<pair<ll, ll>> attacked;
    
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        knights.insert({a, b});
        
        // Check all 8 possible attack positions
        vector<pair<ll, ll>> moves = {
            {a + 2, b + 1}, {a + 1, b + 2},
            {a - 1, b + 2}, {a - 2, b + 1},
            {a - 2, b - 1}, {a - 1, b - 2},
            {a + 1, b - 2}, {a + 2, b - 1}
        };
        
        for (auto [x, y] : moves) {
            if (x >= 0 && x < N && y >= 0 && y < N) {
                if (knights.find({x, y}) == knights.end()) {
                    attacked.insert({x, y});
                }
            }
        }
    }
    
    ll total = N * N;
    ll unsafe = knights.size() + attacked.size();
    cout << total - unsafe << endl;
    
    return 0;
}