#include<bits/stdc++.h>
using namespace std;

int main() {
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
    vector<long long> sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        x[i] = xp[i].first;
        p[i] = xp[i].second;
        sum[i + 1] = sum[i] + p[i];
    }
    
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int l = lower_bound(x.begin(), x.end(), L) - x.begin();
        int r = upper_bound(x.begin(), x.end(), R) - x.begin();
        cout << sum[r] - sum[l] << endl;
    }
    
    return 0;
}