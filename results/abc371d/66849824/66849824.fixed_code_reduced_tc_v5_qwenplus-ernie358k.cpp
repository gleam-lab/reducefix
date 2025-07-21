#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define pb(a) push_back(a)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int N;
    cin >> N;
    vector<ll> P(N + 1), X(N);
    P[0] = 0;
    rep(i, N) cin >> X[i];
    rep(i, N) {
        ll p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }
    map<ll, int> x_to_ptr;
    rep(i, N) {
        x_to_ptr[X[i]] = i;
    }

    int Q;
    cin >> Q;
    rep(q, Q) {
        ll L, R;
        cin >> L >> R;
        auto X_l = x_to_ptr.lower_bound(L);
        auto X_r = x_to_ptr.upper_bound(R);
        int l, r;
        if (X_l == x_to_ptr.end()) {
            l = N;
        } else {
            l = X_l->second;
            // If L is exactly equal to some X[i], we need the index of that X[i]
            if (X_l->first == L) {
                // Do nothing, l is correct
            } else {
                // If L is not exactly equal to some X[i], we need the next index (or N if out of bounds)
                auto it = prev(X_l);
                if (it == x_to_ptr.begin()) {
                    l = 0; // No element smaller than L
                } else {
                    l = it->second;
                }
            }
        }
        if (X_r == x_to_ptr.end()) {
            r = N;
        } else {
            r = prev(X_r)->second; // Use the largest index <= R
        }

        ll ans = P[r + 1] - P[l]; // Note the use of r+1 here, since we want the prefix sum up to but not including the point after r
        cout << ans << endl;
    }
}