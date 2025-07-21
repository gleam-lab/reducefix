#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    vector<ll> rows(N+1), cols(N+1), diag1(2*N+1), diag2(2*N+1);

    for(int i = 0; i < M; ++i) {
        ll r, c;
        cin >> r >> c;
        --r, --c; // Convert to zero-based indexing
        rows[r] = 1;
        cols[c] = 1;
        diag1[r+c] = 1;
        diag2[r-c+N-1] = 1;
    }

    ll ans = 0;
    for(ll r = 0; r < N; ++r) {
        for(ll c = 0; c < N; ++c) {
            if(!rows[r] && !cols[c] && !diag1[r+c] && !diag2[r-c+N-1]) {
                ++ans;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}