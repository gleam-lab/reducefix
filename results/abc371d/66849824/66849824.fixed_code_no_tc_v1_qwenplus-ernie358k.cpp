#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int N;
    cin >> N;
    vector<ll> P(N + 1), X(N);
    P[0] = 0;
    rep(i, N) cin >> X[i];
    rep(i, N) {
        int p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }
    map<int, int> x_to_index;
    rep(i, N) {
        x_to_index[X[i]] = i + 1; // Store 1-based index for easier range calculations
    }

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;
        auto it_l = x_to_index.lower_bound(L);
        auto it_r = x_to_index.upper_bound(R);
        
        int l = (it_l == x_to_index.end()) ? N + 1 : it_l->second; // 1-based index, so N+1 represents beyond last element
        int r = (it_r == x_to_index.end()) ? N + 1 : it_r->second - 1; // Convert to 0-based for P array access
        
        // Adjust r if it's still pointing to an index outside the valid range due to upper_bound
        if (r >= N) r = N - 1;

        ll ans = P[l] - P[r + 1]; // Use r+1 to get the correct prefix sum difference
        cout << ans << endl;
    }
}