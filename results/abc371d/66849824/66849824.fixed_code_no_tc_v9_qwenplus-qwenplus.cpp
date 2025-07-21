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
    vector<ll> P(N + 1);
    vector<ll> X(N);
    
    rep(i, N) cin >> X[i];
    rep(i, N) {
        int p;
        cin >> p;
        P[i+1] = P[i] + p;
    }

    // Make sure X is sorted and we can use binary search
    // Create a vector of pairs (X[i], i) and sort by X[i]
    vector<pair<ll, int>> x_indices;
    rep(i, N) {
        x_indices.push_back({X[i], i});
    }
    sort(all(x_indices));

    // Build prefix sum array
    vector<ll> prefix(N + 1);
    prefix[0] = 0;
    rep(i, N) {
        prefix[i+1] = prefix[i] + P[i+1]; // Adjusted to match original P logic
    }

    // For binary search
    vector<ll> sorted_X;
    rep(i, N) {
        sorted_X.push_back(x_indices[i].first);
    }

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;

        // Use binary search to find the range
        int left = lower_bound(all(sorted_X), L) - sorted_X.begin();
        int right = upper_bound(all(sorted_X), R) - sorted_X.begin();

        // Answer is the sum from index left to right-1 in P
        cout << P[right] - P[left] << endl;
    }
}