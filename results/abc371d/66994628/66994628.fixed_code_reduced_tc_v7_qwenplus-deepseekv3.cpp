#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, q, x[200005], p[200005];
ll sum[200005];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    cin >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        ll left_pos = lower_bound(x + 1, x + n + 1, l) - x;
        ll right_pos = upper_bound(x + 1, x + n + 1, r) - x;
        cout << sum[right_pos - 1] - sum[left_pos - 1] << endl;
    }
    return 0;
}