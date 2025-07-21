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
        auto it_r = x_to_index.upper_bound(R);
        int l_index = (it_l == x_to_index.end()) ? N : it_l->second;
        int r_index = (it_r == x_to_index.end()) ? N : prev(it_r)->second; // Use prev because upper_bound returns one past the last element >= R

        ll ans = P[r_index + 1] - P[l_index]; // Use r_index + 1 because we need the prefix sum up to but not including the element after r_index
        cout << ans << endl;
    }
}