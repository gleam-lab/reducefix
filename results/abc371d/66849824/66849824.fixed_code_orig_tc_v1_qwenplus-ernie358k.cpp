#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> P(N + 1, 0);
    vector<pair<int, int>> X_with_index(N);

    for (int i = 0; i < N; ++i) {
        cin >> X_with_index[i].first;
        X_with_index[i].second = i;
    }

    for (int i = 0; i < N; ++i) {
        int p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }

    sort(X_with_index.begin(), X_with_index.end());

    int Q;
    cin >> Q;

    while (Q--) {
        int L, R;
        cin >> L >> R;

        auto it_l = lower_bound(X_with_index.begin(), X_with_index.end(), make_pair(L, -1));
        auto it_r = upper_bound(X_with_index.begin(), X_with_index.end(), make_pair(R, N));

        int l = (it_l != X_with_index.end()) ? it_l->second : N;
        int r = (it_r != X_with_index.begin()) ? prev(it_r)->second + 1 : N;

        ll ans = P[r] - P[l];
        cout << ans << endl;
    }

    return 0;
}