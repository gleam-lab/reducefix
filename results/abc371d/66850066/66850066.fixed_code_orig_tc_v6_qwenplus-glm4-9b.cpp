#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(a) push_back(a)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int N;
    cin >> N;
    vector<ll> P(N + 1, 0), X(N);
    rep(i, N) cin >> X[i];
    rep(i, N) cin >> P[i + 1];

    // Create a map to associate each value of X with its indices
    map<int, vector<int>> x_to_ptr;
    rep(i, N) x_to_ptr[X[i]].push_back(i);

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;
        auto X_l = x_to_ptr.lower_bound(L);
        auto X_r = x_to_ptr.upper_bound(R);

        // Find the smallest index >= L and the largest index <= R
        int l = 0, r = N - 1;
        if (X_l != x_to_ptr.begin()) {
            --X_l;
            l = x_to_ptr.rbegin()->second[0];
        }
        if (X_r != x_to_ptr.end()) {
            r = x_to_ptr.find((*X_r).first)->second.back();
        }

        // Calculate the sum over the range [L, R]
        int ans = P[r + 1] - P[l];
        cout << ans << endl;
    }
}