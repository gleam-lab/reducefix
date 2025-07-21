#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=105;
int n;
int x;
int a[N],b[N],p[N],q[N];

int c[N];
bool check(int mid) {
    for(int i = 1; i <= n; i++) {
        c[i] = INT_MAX;
        for (int j = 0; j <= b[i]; j++) {
            c[i] = min(c[i], j * p[i] + (q[i] * mid - q[i] * j * a[i] + q[i] * j * b[i] - q[i] * b[i]) / b[i]);
        }
        for (int j = 0; j <= a[i]; j++) {
            c[i] = min(c[i], j * q[i] + (p[i] * mid - p[i] * j * b[i] + p[i] * j * a[i] - p[i] * a[i]) / a[i]);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += c[i];
    }
    return ans <= x;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    int l = 1, r = 1e18;
    while(l < r) {
        int mid = (l + r + 1) / 2;
        if(check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;
    return 0;
}