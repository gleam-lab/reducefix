#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    
    vector<ll> rows(n+1, 0), cols(n+1, 0), diags(2*n+1, 0), anti_diags(2*n+1, 0);
    set<pair<ll, ll>> pieces;

    for(int i=0; i<m; ++i){
        ll r, c;
        cin >> r >> c;
        rows[r]++;
        cols[c]++;
        diags[r+c]++;
        anti_diags[r-c+n]++;
        pieces.insert({r,c});
    }

    ll total_empty_squares = n*n - m;

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            if(pieces.find({i,j}) == pieces.end()){
                bool safe = true;
                if(rows[i] > 1 || cols[j] > 1 || diags[i+j] > 1 || anti_diags[i-j+n] > 1){
                    safe = false;
                }
                if(safe){
                    total_empty_squares++;
                }
            }
        }
    }

    cout << total_empty_squares << endl;

    return 0;
}