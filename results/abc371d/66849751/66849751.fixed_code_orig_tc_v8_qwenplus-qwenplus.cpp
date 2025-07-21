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
    vector<int> X(N);
    vector<ll> P(N + 1, 0);
    rep(i, N) cin >> X[i];
    rep(i, N){
        ll p;
        cin >> p;
        P[i+1] = P[i] + p;
    }

    // Coordinate compression
    vector<int> sorted_X = X;
    sort(all(sorted_X));
    map<int, int> x_to_idx;
    int idx = 0;
    for (int x : sorted_X){
        if (!x_to_idx.count(x)){
            x_to_idx[x] = idx++;
        }
    }

    // Build prefix sums per compressed index
    vector<ll> compressed_sum(idx + 1, 0);
    rep(i, N){
        compressed_sum[x_to_idx[X[i]]] += (P[i+1] - P[i]);
    }

    // Prefix sum over compressed indices
    vector<ll> prefix_sum(idx + 1, 0);
    for (int i = 1; i <= idx; ++i){
        prefix_sum[i] = prefix_sum[i - 1] + compressed_sum[i - 1];
    }

    // Binary search utility functions
    auto get_left = [&](int L) {
        return lower_bound(all(sorted_X), L) - sorted_X.begin();
    };

    auto get_right = [&](int R) {
        return upper_bound(all(sorted_X), R) - sorted_X.begin();
    };

    int Q;
    cin >> Q;
    rep(q, Q){
        int L, R;
        cin >> L >> R;

        int l = get_left(L);
        int r = get_right(R);

        ll ans = prefix_sum[r] - prefix_sum[l];
        cout << ans << "\n";
    }
}