#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;
    
    vector<ll> rows(N+1, 0), cols(N+1, 0), diags(2*N, 0), anti_diags(2*N, 0);
    set<pair<ll,ll>> positions;

    for(int i=0; i<M; ++i){
        ll r, c;
        cin >> r >> c;
        --r; --c; // Adjusting for zero-based indexing
        rows[r] = cols[c] = diags[r+c] = anti_diags[r-c+N-1] = 1;
        positions.emplace(r, c);
    }

    ll count = 0;
    for(ll r=0; r<N; ++r){
        for(ll c=0; c<N; ++c){
            if(!positions.count({r,c}) && !rows[r] && !cols[c] && !diags[r+c] && !anti_diags[r-c+N-1]){
                ++count;
            }
        }
    }

    cout << count << '\n';

    return 0;
}