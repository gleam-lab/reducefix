#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> X_indexed(N);
    rep(i, N) {
        cin >> X_indexed[i].first;
        X_indexed[i].second = i;
    }
    sort(all(X_indexed));

    vector<int> P(N + 1);
    P[0] = 0;
    vector<int> original_p(N);
    rep(i, N) cin >> original_p[i];
    rep(i, N) {
        P[i + 1] = P[i] + original_p[X_indexed[i].second];
    }

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;
        auto lower = lower_bound(all(X_indexed), make_pair(L, 0));
        auto upper = upper_bound(all(X_indexed), make_pair(R, INT_MAX));
        int l = lower - X_indexed.begin();
        int r = upper - X_indexed.begin();
        cout << P[r] - P[l] << endl;
    }
}