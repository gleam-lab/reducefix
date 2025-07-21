#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll N, M;
    cin >> N >> M;
    
    set<pair<ll, ll>> occupied;
    vector<pair<ll, ll>> knight_moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        
        // Add the piece itself
        occupied.emplace(a, b);
        
        // Check all 8 possible attack positions
        for (auto [dx, dy] : knight_moves) {
            ll nx = a + dx;
            ll ny = b + dy;
            
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                occupied.emplace(nx, ny);
            }
        }
    }
    
    // Total squares - attacked or occupied squares
    cout << (N * N - static_cast<ll>(occupied.size())) << '\n';
    
    return 0;
}