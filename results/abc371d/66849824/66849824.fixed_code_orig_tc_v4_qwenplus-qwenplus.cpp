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

    // Create prefix sum array of P
    vector<ll> prefixSum(N+1, 0);
    for(int i = 1; i <= N; ++i){
        prefixSum[i] = prefixSum[i-1] + P[i];
    }

    // Build mapping from X[i] to index i (sorted)
    map<ll, int> x_to_idx;
    rep(i, N){
        x_to_idx[X[i]] = i;
    }

    // Build sorted list of X values
    vector<ll> sortedX = X;
    sort(sortedX.begin(), sortedX.end());

    int Q;
    cin >> Q;
    rep(q, Q){
        ll L, R;
        cin >> L >> R;

        // Use binary search to find lower and upper bounds in sortedX
        auto left = lower_bound(sortedX.begin(), sortedX.end(), L);
        auto right = upper_bound(sortedX.begin(), sortedX.end(), R);

        // If no elements in range
        if(left == sortedX.end() || right == sortedX.begin()){
            cout << 0 << endl;
            continue;
        }

        // Get indices in original array
        int l_idx = distance(sortedX.begin(), left);
        int r_idx = distance(sortedX.begin(), right);

        // Since the data is up to 2e5, we need to use 64-bit integers
        ll total = 0;
        if(r_idx > 0){
            total = prefixSum[r_idx] - prefixSum[l_idx];
        }

        cout << total << endl;
    }

    return 0;
}