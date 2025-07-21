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
        x_to_index[X[i]] = i;
    }

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;
        auto it_l = x_to_index.lower_bound(L);
        int l = (it_l == x_to_index.end()) ? N : it_l->second;
        
        // Use upper_bound with a slight trick to find the correct r
        // Since upper_bound returns an iterator to the first element greater than R,
        // we need to decrement it and then check if it's still within bounds.
        auto it_r = x_to_index.upper_bound(R);
        int r = (it_r == x_to_index.begin()) ? 0 : prev(it_r)->second + 1;
        if (r > N) r = N;

        ll ans = P[r] - P[l];
        cout << ans << endl;
    }

    return 0;
}