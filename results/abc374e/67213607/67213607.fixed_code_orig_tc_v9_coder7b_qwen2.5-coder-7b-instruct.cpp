#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
long long n, x, a[MAXN], p[MAXN], b[MAXN], q[MAXN], l, r, mid, ans, minn, sum;

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    
    l = 0, r = 1000000005;
    while (l <= r) {
        mid = (l + r) / 2;
        sum = 0;
        
        for (int i = 1; i <= n; ++i) {
            minn = LLONG_MAX;
            
            // Calculate minimum cost for type A
            for (int j = 0; j <= b[i]; ++j) {
                long long remaining = mid - j * a[i];
                if (remaining >= 0) {
                    long long cost = j * p[i];
                    if (remaining % b[i] == 0)
                        cost += (remaining / b[i]) * q[i];
                    else
                        cost += ((remaining / b[i]) + 1) * q[i];
                    
                    minn = min(minn, cost);
                }
            }
            
            // Calculate minimum cost for type B
            for (int j = 0; j <= a[i]; ++j) {
                long long remaining = mid - j * b[i];
                if (remaining >= 0) {
                    long long cost = j * q[i];
                    if (remaining % a[i] == 0)
                        cost += (remaining / a[i]) * p[i];
                    else
                        cost += ((remaining / a[i]) + 1) * p[i];
                    
                    minn = min(minn, cost);
                }
            }
            
            sum += minn;
        }
        
        if (sum <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    cout << ans;
    return 0;
}