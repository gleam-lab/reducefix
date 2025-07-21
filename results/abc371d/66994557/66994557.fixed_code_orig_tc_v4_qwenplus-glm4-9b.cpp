#include<bits/stdc++.h>
using namespace std;

int n, q;
int x[200005], p[200005];
long long sum[2000005];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (i == 0) {
            sum[i] = p[i];
        } else {
            sum[i] = sum[i-1] + p[i];
        }
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int l = lower_bound(x, x + n, L) - x;
        int r = upper_bound(x, x + n, R) - x - 1;
        cout << sum[r] - sum[l - 1] << endl;
    }
    return 0;
}