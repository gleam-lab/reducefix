#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define reps(i, n) for (int i = 0; i <= n; ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
    rep(i, N) {
        ll p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }
    
    // Create a map to store the latest occurrence of each point
    map<int, int> x_to_ptr;
    for (int i = N - 1; i >= 0; --i) {
        x_to_ptr.emplace(X[i], i);
    }
    
    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;
        auto X_l = x_to_ptr.lower_bound(L);
        auto X_r = x_to_ptr.upper_bound(R);
        
        // Check if the range is within the bounds of the points
        if (X_l == x_to_ptr.begin() && (*X_l).first > L) {
            cout << "Invalid range\n";
            continue;
        }
        if (X_r == x_to_ptr.end() || (*X_r).first < R) {
            cout << "Invalid range\n";
            continue;
        }
        
        int l = (*X_l).second;
        int r = (*X_r).second;
        int ans = P[r] - P[l];
        cout << ans << endl;
    }
    return 0;
}