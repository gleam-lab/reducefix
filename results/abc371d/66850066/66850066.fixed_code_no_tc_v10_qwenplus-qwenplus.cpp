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
    vector<ll> P(N+1, 0);
    vector<ll> X(N);

    rep(i, N) cin >> X[i];
    rep(i, N) {
        ll p;
        cin >> p;
        P[i+1] = P[i] + p;
    }

    // Create a sorted vector of pairs (X[i], i) to enable binary search
    vector<pair<ll, int>> x_with_index(N);
    rep(i, N) {
        x_with_index[i] = {X[i], i};
    }
    sort(all(x_with_index));

    // Extract sorted X positions and corresponding prefix sum indices
    vector<ll> sorted_X(N);
    vector<int> x_to_prefix_idx(N);
    rep(i, N) {
        sorted_X[i] = x_with_index[i].first;
        x_to_prefix_idx[i] = x_with_index[i].second + 1; // index in prefix sum array
    }

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;

        // Binary search on sorted_X to find range [L, R]
        int left = lower_bound(all(sorted_X), L) - sorted_X.begin();
        int right = upper_bound(all(sorted_X), R) - sorted_X.begin();

        // Map the found indices to the prefix sum array
        int l = (left < N) ? x_to_prefix_idx[left] : N;
        int r = (right < N) ? x_to_prefix_idx[right] : N;

        int ans = P[r] - P[l];
        cout << ans << endl;
    }

    return 0;
}