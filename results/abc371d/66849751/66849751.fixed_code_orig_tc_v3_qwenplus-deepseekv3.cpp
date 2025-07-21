#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> X(N);
    vector<ll> P(N + 1, 0);
    
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    
    for (int i = 0; i < N; ++i) {
        int p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }

    vector<pair<int, int>> x_indexed(N);
    for (int i = 0; i < N; ++i) {
        x_indexed[i] = {X[i], i};
    }
    sort(x_indexed.begin(), x_indexed.end());

    vector<int> sorted_X(N);
    for (int i = 0; i < N; ++i) {
        sorted_X[i] = x_indexed[i].first;
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int L, R;
        cin >> L >> R;
        
        auto it_l = lower_bound(sorted_X.begin(), sorted_X.end(), L);
        auto it_r = upper_bound(sorted_X.begin(), sorted_X.end(), R);
        
        int l = it_l - sorted_X.begin();
        int r = it_r - sorted_X.begin();
        
        ll ans = P[x_indexed[r - 1].second + 1] - P[x_indexed[l].second];
        cout << ans << '\n';
    }

    return 0;
}