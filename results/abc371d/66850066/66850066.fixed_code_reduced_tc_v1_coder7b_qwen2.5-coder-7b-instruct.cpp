#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> X(N), P(N + 1);
    rep(i, N) cin >> X[i];
    rep(i, N) {
        ll p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }

    map<int, int> x_to_ptr;
    rep(i, N) {
        x_to_ptr[X[i]] = i;
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int L, R;
        cin >> L >> R;
        auto it_l = x_to_ptr.lower_bound(L);
        auto it_r = x_to_ptr.upper_bound(R);

        if (it_l == x_to_ptr.end()) continue; // If no element is found greater than or equal to L
        if (it_r == x_to_ptr.begin()) continue; // If no element is found less than or equal to R

        --it_r; // Adjust iterator to point to the last element that is less than or equal to R

        int l = it_l->second;
        int r = it_r->second;

        ll ans = P[r + 1] - P[l];
        cout << ans << '\n';
    }

    return 0;
}