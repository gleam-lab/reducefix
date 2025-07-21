#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define reps(i, n) for (int i = 0; i <= (n); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb(a) push_back(a)
#define Yes(b) cout << ((b) ? "Yes" : "No") << endl
#define YES(b) cout << ((b) ? "YES" : "NO") << endl

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int N;
    cin >> N;
    vector<int> X(N), P(N + 1);
    rep(i, N) cin >> X[i];
    rep(i, N) {
        int p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }

    map<int, int> x_to_ptr;
    rep(i, N) {
        x_to_ptr[X[i]] = i;
    }

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R, l, r;
        cin >> L >> R;

        // Find the first position greater than or equal to L
        auto X_l = x_to_ptr.lower_bound(L);
        // If L is not found, set l to the size of P
        l = X_l == x_to_ptr.end() ? N : (*X_l).second;

        // Find the first position strictly greater than R
        auto X_r = x_to_ptr.upper_bound(R);
        // If R is not found, set r to the size of P
        r = X_r == x_to_ptr.end() ? N : (*X_r).second;

        // Adjust r to include the rightmost point if R is an exact match
        if (!x_to_ptr.empty() && X_r != x_to_ptr.begin()) {
            --X_r;
            if ((*X_r).first == R) {
                r = (*X_r).second + 1;
            }
        }

        int ans = P[r] - P[l];
        cout << ans << endl;
    }
}