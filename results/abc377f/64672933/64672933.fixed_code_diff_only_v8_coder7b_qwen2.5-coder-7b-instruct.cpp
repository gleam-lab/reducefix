#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N, M;
    cin >> N >> M;
    
    set<ll> rows, cols, diags, anti_diags;
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diags.insert(a + b);
        anti_diags.insert(a - b);
    }
    
    ll valid_positions = 0;
    for (ll i = 1; i <= N; ++i) {
        for (ll j = 1; j <= N; ++j) {
            if (rows.find(i) == rows.end() && 
                cols.find(j) == cols.end() && 
                diags.find(i + j) == diags.end() && 
                anti_diags.find(i - j) == anti_diags.end()) {
                ++valid_positions;
            }
        }
    }
    
    cout << valid_positions << endl;
    
    return 0;
}