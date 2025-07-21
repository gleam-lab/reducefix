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
    int N;
    cin >> N;
    vector<ll> P(N+1), X(N);
    rep(i, N) cin >> X[i];
    P[0] = 0;
    rep(i, N){
        ll p;
        cin >> p;
        P[i+1] = P[i] + p;
    }

    // Create a sorted vector of pairs instead of map to handle duplicates properly
    vector<pair<ll, ll>> x_p(N);
    rep(i, N){
        x_p[i] = {X[i], i};
    }
    sort(all(x_p));

    // Build prefix sums
    vector<ll> prefix(N+1);
    prefix[0] = 0;
    rep(i, N){
        prefix[i+1] = prefix[i] + P[i+1];
    }

    int Q;
    cin >> Q;
    rep(q, Q){
        ll L, R;
        cin >> L >> R;

        // Use binary search on the sorted vector
        auto left = lower_bound(all(x_p), make_pair(L, -1LL));
        auto right = upper_bound(all(x_p), make_pair(R, numeric_limits<ll>::max()));

        int l_idx = left - x_p.begin();
        int r_idx = right - x_p.begin();

        ll ans = prefix[r_idx] - prefix[l_idx];
        cout << ans << endl;
    }
}