#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;

// Direction vectors for all 8 possible L-shaped moves
const vector<pair<ll, ll>> dirs = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

int main() {
    ll N, M;
    cin >> N >> M;

    set<pair<ll, ll>> occupied;
    
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        occupied.emplace(a, b);
        
        // Check all 8 potential attack positions
        for (auto [dx, dy] : dirs) {
            ll nx = a + dx;
            ll ny = b + dy;
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                occupied.emplace(nx, ny);
            }
        }
    }

    // The total number of squares is N*N
    // Subtract the number of occupied or threatened squares
    cout << (N * N - (ll)occupied.size()) << endl;
    
    return 0;
}