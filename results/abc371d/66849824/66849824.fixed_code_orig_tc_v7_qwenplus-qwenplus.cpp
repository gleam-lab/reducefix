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
    cin.tie(0);

    int N;
    cin >> N;
    vector<ll> P(N+1), X(N);
    P[0] = 0;
    rep(i, N) cin >> X[i];
    rep(i, N){
        ll p;
        cin >> p;
        P[i+1] = P[i] + p;
    }

    // Create prefix sum array of X values
    vector<pair<ll, ll>> sortedX_P;
    rep(i, N){
        sortedX_P.push_back({X[i], P[i+1]});
    }
    sort(all(sortedX_P));

    vector<ll> prefix_sums(N+1, 0);
    rep(i, N){
        prefix_sums[i+1] = prefix_sums[i] + sortedX_P[i].second;
    }

    vector<ll> x_values;
    rep(i, N){
        x_values.push_back(sortedX_P[i].first);
    }

    // Process queries
    int Q;
    cin >> Q;
    rep(q, Q){
        ll L, R;
        cin >> L >> R;

        auto l_ptr = lower_bound(all(x_values), L);
        auto r_ptr = upper_bound(all(x_values), R);

        int left_idx = l_ptr - x_values.begin();
        int right_idx = r_ptr - x_values.begin();

        ll ans = prefix_sums[right_idx] - prefix_sums[left_idx];
        cout << ans << "\n";
    }

    return 0;
}