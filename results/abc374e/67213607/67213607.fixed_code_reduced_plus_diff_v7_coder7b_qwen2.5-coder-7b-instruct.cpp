#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;
long long n, x, a[MAXN], p[MAXN], b[MAXN], q[MAXN], l, r, mid, ans, minn, sum;

int main() {
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    l = 0, r = 1000000005;
    while(l <= r) {
        mid = (l + r) / 2;
        sum = 0;
        for(int i = 1; i <= n; i++) {
            minn = LLONG_MAX;
            // Calculate cost for type A
            for(int j = 0; j <= a[i]; j++) {
                if(mid - j * b[i] >= 0) {
                    minn = min(minn, j * q[i] + (mid - j * b[i]) / a[i] * p[i]);
                } else {
                    break;
                }
            }
            // Calculate cost for type B
            for(int j = 0; j <= b[i]; j++) {
                if(mid - j * a[i] >= 0) {
                    minn = min(minn, j * p[i] + (mid - j * a[i]) / b[i] * q[i]);
                } else {
                    break;
                }
            }
            sum += minn;
        }
        if(sum <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}