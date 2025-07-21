#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<long long> x(n + 1), p(n + 1), sum(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    
    int q;
    cin >> q;
    while (q--) {
        long long l, r;
        cin >> l >> r;
        int left = lower_bound(x.begin() + 1, x.end(), l) - x.begin();
        int right = upper_bound(x.begin() + 1, x.end(), r) - x.begin();
        cout << sum[right - 1] - sum[left - 1] << '\n';
    }
    
    return 0;
}