#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    set<pair<ll, ll>> unsafe;
    set<pair<ll, ll>> pieces;

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        
        // Check all 8 possible knight moves
        vector<pair<ll, ll>> moves = {
            {a+2, b+1}, {a+1, b+2},
            {a-1, b+2}, {a-2, b+1},
            {a-2, b-1}, {a-1, b-2},
            {a+1, b-2}, {a+2, b-1}
        };
        
        for (auto [x, y] : moves) {
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                unsafe.insert({x, y});
            }
        }
    }
    
    // The safe positions are N^2 - unsafe.size() - (pieces not in unsafe)
    // But pieces are already occupied, so they are not empty
    ll total = N * N - unsafe.size() - M + count_if(pieces.begin(), pieces.end(), [&unsafe](const pair<ll, ll>& p) {
        return unsafe.count(p);
    });
    
    cout << total << endl;
    return 0;
}