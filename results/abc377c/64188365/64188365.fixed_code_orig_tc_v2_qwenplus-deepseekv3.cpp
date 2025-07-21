#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    set<pair<ll, ll>> pieces;
    set<pair<ll, ll>> threatened;

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        
        // All 8 possible knight moves
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        
        for (int k = 0; k < 8; ++k) {
            ll ni = a + dx[k];
            ll nj = b + dy[k];
            if (ni >= 1 && ni <= N && nj >= 1 && nj <= N) {
                if (pieces.find({ni, nj}) == pieces.end()) {
                    threatened.insert({ni, nj});
                }
            }
        }
    }

    ll total_squares = N * N;
    ll occupied = M;
    ll unsafe = threatened.size();
    ll safe = total_squares - occupied - unsafe;
    
    cout << safe << endl;
    return 0;
}