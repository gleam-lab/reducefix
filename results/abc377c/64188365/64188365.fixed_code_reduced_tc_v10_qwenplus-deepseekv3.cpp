#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    set<pair<ll, ll>> existing_pieces;
    set<pair<ll, ll>> dangerous_positions;
    
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        existing_pieces.emplace(a, b);
        
        // Generate all 8 possible dangerous positions for each existing piece
        for (int di = -2; di <= 2; di++) {
            for (int dj = -2; dj <= 2; dj++) {
                if (abs(di) + abs(dj) == 3) {
                    ll ni = a + di;
                    ll nj = b + dj;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                        dangerous_positions.emplace(ni, nj);
                    }
                }
            }
        }
    }
    
    // The total safe positions are total positions minus existing pieces minus dangerous positions not already existing
    ll total_safe = n * n - existing_pieces.size();
    for (auto pos : dangerous_positions) {
        if (existing_pieces.find(pos) == existing_pieces.end()) {
            total_safe--;
        }
    }
    
    cout << total_safe << endl;
}