#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i,n) for (int i=0; i<(n); ++i)
#define reps(i,n) for (int i=0; i<=(n); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb(a) push_back(a)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int N;
    cin >> N;
    vector<int> P(N + 1), X(N);
    
    rep(i, N) cin >> X[i];
    rep(i, N) {
        int p;
        cin >> p;
        P[i+1] = P[i] + p;
    }

    // Create prefix sum of P
    // Already handled in the input loop

    // Build map from coordinate to index (for binary searching)
    map<int, int> x_to_idx;
    rep(i, N) {
        x_to_idx[X[i]] = i;
    }

    // For efficient range queries, create a vector of pairs
    vector<pair<int, int>> sorted_coords(N);
    rep(i, N) {
        sorted_coords[i] = {X[i], i};
    }
    sort(all(sorted_coords));

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;

        // Find left bound
        int left_idx = 0;
        auto it_left = lower_bound(all(sorted_coords), make_pair(L, -1));
        if (it_left != sorted_coords.begin()) {
            --it_left;
            left_idx = it_left->second;
        } else {
            left_idx = 0;
        }

        // Find right bound
        int right_idx = N;
        auto it_right = upper_bound(all(sorted_coords), make_pair(R, N));
        if (it_right != sorted_coords.end()) {
            right_idx = it_right->second;
        }

        // Calculate result
        int ans = P[right_idx] - P[left_idx];
        cout << ans << endl;
    }

    return 0;
}