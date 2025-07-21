#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    set<pair<ll, ll>> pieces;
    set<pair<ll, ll>> attacked;
    
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--; b--; // converting to 0-based or 1-based doesn't matter as long as consistent
        pieces.insert({a, b});
        
        // All 8 possible knight moves
        ll dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        ll dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        
        rep(k, 8) {
            ll ni = a + dx[k];
            ll nj = b + dy[k];
            if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
                attacked.insert({ni, nj});
            }
        }
    }
    
    // The safe positions are N*N minus (attacked positions + existing pieces)
    // But existing pieces are already in 'pieces' and some might be in 'attacked'
    // So total unsafe positions are the union of 'pieces' and 'attacked'
    set<pair<ll, ll>> unsafe;
    for (auto p : pieces) unsafe.insert(p);
    for (auto p : attacked) unsafe.insert(p);
    
    ll safe = N * N - unsafe.size();
    cout << safe << endl;
}