#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n;
    vector<pair<int, int>> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> data[i].second;
    }
    
    sort(data.begin(), data.end());
    vector<int> x(n), p(n);
    for (int i = 0; i < n; i++) {
        x[i] = data[i].first;
        p[i] = data[i].second;
    }
    
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + p[i - 1];
    }
    
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int l = lower_bound(x.begin(), x.end(), L) - x.begin();
        int r = upper_bound(x.begin(), x.end(), R) - x.begin();
        cout << sum[r] - sum[l] << '\n';
    }
    
    return 0;
}