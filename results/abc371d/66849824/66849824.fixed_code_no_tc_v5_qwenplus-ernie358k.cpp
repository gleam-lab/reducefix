#include <iostream>
#include <vector>
#include <map>
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
    map<int, int> x_to_index;
    rep(i, N) {
        x_to_index[X[i]] = i + 1; // Store 1-based index for easier range calculation
    }

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;
        auto it_l = x_to_index.lower_bound(L);
        auto it_r = x_to_index.upper_bound(R);
        int l = (it_l == x_to_index.end()) ? (N + 1) : it_l->second;
        int r = (it_r == x_to_index.end()) ? (N + 1) : it_r->second - 1; // Convert to 0-based index for P array

        // Since we stored 1-based indices, convert back to 0-based for prefix sums if necessary
        ll ans = (l <= N) ? P[l] : 0;
        if (r < N) {
            ans -= P[r + 1]; // Subtract the prefix sum up to (r+1) to get the range [r+1, l) in 0-based index
        } else {
            ans = 0; // If r is out of bounds, the answer is 0
        }
        cout << ans << endl;
    }
}