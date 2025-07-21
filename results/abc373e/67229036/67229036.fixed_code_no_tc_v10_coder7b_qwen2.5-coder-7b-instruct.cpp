#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,m,k,sum,cnt,a[N],b[N],c[N];

// Function to check if candidate i can win with at least 'x' more votes
bool check(int i, int x) {
    int z = upper_bound(b + 1, b + 1 + n, x + a[i]) - b - 1;
    if (z < n - m) return false;
    return (x + a[i] + 1) * (z - n + m) > k - sum;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int i, j, x, y, z, t;
    cin >> n >> m >> k;
    for (i = 1; i <= n; ++i) {
        cin >> a[i]; 
        k -= a[i]; 
        sum += a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for (i = 1; i <= n; ++i) {
        c[i] = c[i - 1] + b[i];
    }

    for (i = 1; i <= n; ++i) {
        int l = 0, r = k + 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(i, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (l <= k) {
            cout << l << " ";
        } else {
            cout << "-1 ";
        }
    }
    return 0;
}