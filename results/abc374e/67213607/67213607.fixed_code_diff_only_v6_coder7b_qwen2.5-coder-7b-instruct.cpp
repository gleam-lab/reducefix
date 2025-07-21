#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int INF = 2e9;

int n, x, a[MAXN], p[MAXN], b[MAXN], q[MAXN];
int l, r, mid, ans, minn, sum;

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    l = 0, r = 1000000005;
    while (l <= r) {
        mid = (l + r) / 2;
        sum = 0;
        for (int i = 1; i <= n; i++) {
            minn = INF;
            for (int j = 0; j <= b[i]; j++) {
                int cost = j * p[i];
                if ((mid - j * a[i]) > 0) {
                    cost += (mid - j * a[i]) / b[i] * q[i];
                    if ((mid - j * a[i]) % b[i] != 0) cost += q[i];
                }
                minn = min(minn, cost);
            }
            for (int j = 0; j <= a[i]; j++) {
                int cost = j * q[i];
                if ((mid - j * b[i]) > 0) {
                    cost += (mid - j * b[i]) / a[i] * p[i];
                    if ((mid - j * b[i]) % a[i] != 0) cost += p[i];
                }
                minn = min(minn, cost);
            }
            sum += minn;
        }
        if (sum <= x) {
            ans = max(ans, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}