#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define pb(a) push_back(a)
#define Yes(b) cout << ((b) ? "Yes\n" : "No\n")
#define YES(b) cout << ((b) ? "YES\n" : "NO\n")

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int N;
    cin >> N;
    vector<ll> P(N + 1), X(N);
    P[0] = 0;
    rep(i, N) cin >> X[i];
    rep(i, N) cin >> P[i + 1];
    
    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;

        // If L is the last value, we subtract the whole array sum from R
        if (L == P[N]) {
            cout << R << endl;
            continue;
        }

        // Find the lower bound of L in X and adjust the index if necessary
        auto it = lower_bound(X.begin(), X.end(), L);
        int left_index = (it - X.begin());

        // Find the upper bound of R in X and adjust the index if necessary
        it = upper_bound(X.begin(), X.end(), R);
        int right_index = (it - X.begin()) - 1;

        // If L was the last element, we should not subtract the sum again
        if (left_index == 0) {
            cout << P[right_index + 1] << endl;
        } else {
            cout << P[right_index + 1] - P[left_index] << endl;
        }
    }

    return 0;
}