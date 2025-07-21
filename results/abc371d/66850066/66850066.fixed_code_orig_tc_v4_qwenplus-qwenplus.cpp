#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i,n) for (int i=0; i<(n); ++i)
#define reps(i,n) for (int i=0; i<=(n); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb(a) push_back(a)
#define Yes(b) cout << ((b)?"Yes":"No") << endl
#define YES(b) cout << ((b)?"YES":"NO") << endl

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> X(N), P(N+1);
    P[0] = 0;
    rep(i, N) cin >> X[i];
    rep(i, N){
        ll p;
        cin >> p;
        P[i+1] = P[i] + p;
    }

    // Build prefix sums and sorted indices by X coordinate
    vector<pair<ll, int>> x_idx(N);
    rep(i, N) x_idx[i] = {X[i], i};
    sort(all(x_idx));

    // Precompute prefix sums of P at each point in the sorted order
    vector<ll> prefix_sums(N+1, 0);
    rep(i, N) {
        prefix_sums[i+1] = prefix_sums[i] + P[i+1] - P[i]; // same as P[i+1]
    }

    int Q;
    cin >> Q;
    rep(q, Q){
        ll L, R;
        cin >> L >> R;

        // Use binary search to find lower and upper bounds
        auto left = lower_bound(all(x_idx), make_pair(L, -1));
        auto right = upper_bound(all(x_idx), make_pair(R, N));

        int l_idx = left - x_idx.begin();
        int r_idx = right - x_idx.begin();

        // Sum of importance values between l_idx and r_idx in prefix_sums
        ll ans = prefix_sums[r_idx] - prefix_sums[l_idx];
        cout << ans << "\n";
    }
}