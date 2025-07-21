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
    vector<ll> P(N+1, 0);
    rep(i, N) {
        cin >> X[i];
    }
    rep(i, N) {
        int p;
        cin >> p;
        P[i+1] = P[i] + p;
    }

    // Prepare prefix sums and sorted indices based on X values
    vector<pair<int, int>> sortedX;
    rep(i, N) {
        sortedX.emplace_back(X[i], i);
    }
    sort(all(sortedX));

    // Extract the sorted positions and prefix sums
    vector<int> sorted_pos(N);
    vector<ll> prefix_sums(N + 1, 0);
    rep(i, N) {
        sorted_pos[i] = sortedX[i].first;
        prefix_sums[i + 1] = prefix_sums[i] + sortedX[i].second;
    }

    // Build mapping from original index to sorted index using coordinate compression
    vector<int> x_to_index(N);
    rep(i, N) {
        x_to_index[i] = sortedX[i].second;
    }

    // Create a mapping from original index to prefix sum up to that point
    vector<ll> indexed_prefix(N + 1, 0);
    rep(i, N) {
        indexed_prefix[x_to_index[i] + 1] = P[i + 1];
    }

    // Build prefix sum over the indexed data
    vector<ll> final_prefix(N + 1, 0);
    rep(i, N) {
        final_prefix[i + 1] = final_prefix[i] + indexed_prefix[i + 1];
    }

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;

        // Binary search to find lower and upper bounds in sorted X values
        int l = lower_bound(sorted_pos.begin(), sorted_pos.end(), L) - sorted_pos.begin();
        int r = upper_bound(sorted_pos.begin(), sorted_pos.end(), R) - sorted_pos.begin();

        // The result is the difference in the prefix sums
        ll ans = final_prefix[r] - final_prefix[l];
        cout << ans << "\n";
    }

    return 0;
}