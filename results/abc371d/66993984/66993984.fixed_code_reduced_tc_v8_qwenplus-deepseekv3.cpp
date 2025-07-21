#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    vector<pair<int, int>> xp(n);
    for (int i = 0; i < n; ++i) {
        cin >> xp[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> xp[i].second;
    }
    sort(xp.begin(), xp.end());

    vector<int> x(n), p(n);
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        x[i] = xp[i].first;
        p[i] = xp[i].second;
        prefix[i + 1] = prefix[i] + p[i];
    }

    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int c = lower_bound(x.begin(), x.end(), L) - x.begin();
        int d = upper_bound(x.begin(), x.end(), R) - x.begin();
        cout << (prefix[d] - prefix[c]) << '\n';
    }

    return 0;
}