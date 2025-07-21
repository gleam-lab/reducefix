#include<bits/stdc++.h>
using namespace std;

int n, q;
long long x[200005], p[200005];
long long sum[2000005];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        sum[i + 1] = sum[i] + p[i];
    }
    cin >> q;
    while (q--) {
        long long L, R;
        cin >> L >> R;
        auto it_l = lower_bound(x, x + n, L);
        auto it_r = upper_bound(x, x + n, R);
        cout << sum[it_r - x] - sum[it_l - x] << endl;
    }
    return 0;
}