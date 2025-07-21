#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()

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
    
    // No need for map, just sort X and store indices
    vector<pair<ll, int>> indexed_X(N);
    rep(i, N) indexed_X[i] = {X[i], i};
    sort(indexed_X.begin(), indexed_X.end());
    
    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;
        auto it = lower_bound(indexed_X.begin(), indexed_X.end(), make_pair(L, 0));
        auto it_upper = upper_bound(indexed_X.begin(), indexed_X.end(), make_pair(R, 0));
        
        int l = (it != indexed_X.begin()) ? (it - 1)->second : 0;
        int r = (it_upper != indexed_X.end()) ? it_upper->second : N - 1;
        
        ll ans = P[r + 1] - P[l];
        cout << ans << endl;
    }
    
    return 0;
}