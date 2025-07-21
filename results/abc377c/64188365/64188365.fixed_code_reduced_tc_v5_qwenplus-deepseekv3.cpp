#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    set<pair<ll, ll>> attacked;
    set<pair<ll, ll>> pieces;
    
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        pieces.insert({a, b});
        
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        
        rep(j, 8) {
            ll ni = a + dx[j] - 1;
            ll nj = b + dy[j] - 1;
            if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                attacked.insert({ni, nj});
            }
        }
    }
    
    ll total = n * n;
    ll unsafe = attacked.size() + pieces.size();
    // Need to subtract the intersections where a piece is also in attacked positions
    for (auto piece : pieces) {
        if (attacked.count(piece)) {
            unsafe--;
        }
    }
    
    cout << total - unsafe << endl;
}