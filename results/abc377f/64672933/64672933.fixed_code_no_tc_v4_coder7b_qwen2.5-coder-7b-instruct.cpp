#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N, M;
    cin >> N >> M;
    
    vector<ll> rows(N+1, 0);
    vector<ll> cols(N+1, 0);
    unordered_set<ll> diagonals;
    unordered_set<ll> antiDiagonals;
    
    for(int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        --a, --b; // Convert to zero-based index
        
        rows[a]++;
        cols[b]++;
        
        diagonals.insert(a + b);
        antiDiagonals.insert(a - b);
    }
    
    ll validSquares = 0;
    
    for(ll i = 0; i < N; ++i) {
        for(ll j = 0; j < N; ++j) {
            if(rows[i] == 0 && cols[j] == 0 && !diagonals.count(i + j) && !antiDiagonals.count(i - j)) {
                ++validSquares;
            }
        }
    }
    
    cout << validSquares << "\n";
    
    return 0;
}