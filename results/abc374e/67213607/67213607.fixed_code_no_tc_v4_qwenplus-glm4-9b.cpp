#include<bits/stdc++.h>
using namespace std;
long long n, x, a[105], b[105], p[105], q[105], l, r, mid, ans, minn, sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    
    l = 1;
    r = 1000000005;
    ans = 0;
    while (l <= r) {
        mid = l + (r - l) / 2;
        sum = 0;
        for (int i = 1; i <= n; i++) {
            minn = 210000000000000000;
            // Process the first inequality
            if (mid < a[i] * b[i]) {
                minn = min(minn, (b[i] - (mid - a[i] * b[i]) / a[i]) * p[i]);
            } else {
                minn = min(minn, (mid - a[i] * b[i]) / b[i] * q[i] + (b[i] - (mid - a[i] * b[i]) / b[i]) * p[i]);
            }
            
            // Process the second inequality
            if (mid < b[i] * a[i]) {
                minn = min(minn, (a[i] - (mid - b[i] * a[i]) / b[i]) * q[i]);
            } else {
                minn = min(minn, (mid - b[i] * a[i]) / a[i] * p[i] + (a[i] - (mid - b[i] * a[i]) / a[i]) * q[i]);
            }
            
            sum += minn;
        }
        
        if (sum <= x) {
            ans = mid;  // mid is a valid answer but might not be the maximum one
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    cout << ans;
    return 0;
}