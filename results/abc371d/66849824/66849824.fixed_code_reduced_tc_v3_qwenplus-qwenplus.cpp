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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int N;
    cin >> N;
    vector<ll> P(N + 1), X(N);
    rep(i, N) cin >> X[i];
    rep(i, N) {
        ll p;
        cin >> p;
        P[i+1] = P[i] + p;
    }

    // Create a vector of pairs to store both X[i] and its index
    vector<pair<ll, int>> sorted_X(N);
    rep(i, N) {
        sorted_X[i] = {X[i], i};
    }
    // Sort the vector based on X values
    sort(all(sorted_X));

    // Build prefix sum array
    vector<ll> prefix_sum(N + 1, 0);
    rep(i, N) {
        prefix_sum[i+1] = prefix_sum[i] + P[i+1];  // Adjust this based on your actual data structure
    }

    int Q;
    cin >> Q;
    rep(q, Q) {
        ll L, R;
        cin >> L >> R;

        // Use binary search to find the range in one operation
        pair<ll, int> lower_bound_L = {L, 0};
        pair<ll, int> upper_bound_R = {R, N};

        // Find left index using lower_bound
        auto l_it = lower_bound(sorted_X.begin(), sorted_X.end(), lower_bound_L);
        int l_idx = l_it - sorted_X.begin();

        // Find right index using upper_bound
        auto r_it = upper_bound(sorted_X.begin(), sorted_X.end(), upper_bound_R);
        int r_idx = r_it - sorted_X.begin();

        // Get the prefix sums
        ll ans = P[r_idx] - P[l_idx];
        cout << ans << endl;
    }
}