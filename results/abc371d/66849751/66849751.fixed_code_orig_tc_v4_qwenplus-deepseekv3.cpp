#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> X(N), P(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    vector<pair<int, int>> elements(N);
    for (int i = 0; i < N; ++i) {
        elements[i] = {X[i], P[i]};
    }
    sort(elements.begin(), elements.end());

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + elements[i].second;
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int L, R;
        cin >> L >> R;
        
        auto it_l = lower_bound(elements.begin(), elements.end(), make_pair(L, 0));
        auto it_r = upper_bound(elements.begin(), elements.end(), make_pair(R, INT_MAX));
        
        int l = distance(elements.begin(), it_l);
        int r = distance(elements.begin(), it_r);
        
        ll ans = prefix[r] - prefix[l];
        cout << ans << '\n';
    }

    return 0;
}