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
    vector<ll> P(N+1), X(N);
    P[0] = 0;
    rep(i, N) cin >> X[i];
    rep(i, N){
        ll p;
        cin >> p;
        P[i+1] = P[i] + p;
    }

    // Create prefix sum array of P
    vector<ll> prefix_sum(N+1);
    for(int i = 1; i <= N; ++i){
        prefix_sum[i] = prefix_sum[i-1] + P[i];
    }

    // Build a sorted list of pairs (X[i], i)
    vector<pair<ll, int>> sorted_X;
    rep(i, N) {
        sorted_X.emplace_back(X[i], i);
    }
    sort(all(sorted_X));

    int Q;
    cin >> Q;
    rep(q, Q){
        int L, R;
        cin >> L >> R;

        // Binary search to find the lower bound index
        auto left = lower_bound(sorted_X.begin(), sorted_X.end(), make_pair((ll)L, -1));
        auto right = upper_bound(sorted_X.begin(), right_X.end(), make_pair((ll)R, N+1));

        int l_idx = left - sorted_X.begin();
        int r_idx = right - sorted_X.begin();

        // Use prefix sums to calculate the answer
        ll ans = prefix_sum[r_idx] - prefix_sum[l_idx];
        cout << ans << endl;
    }

    return 0;
}