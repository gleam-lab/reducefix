#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,m,k,sum,cnt,a[N],b[N],c[N];

// Function to calculate the minimum additional votes needed
bool check(int x, int y) {
    // Calculate the rank of candidate i + x + 1
    int z = lower_bound(b + 1, b + 1 + n, x + y + 1) - b - 1;
    // Check if the number of candidates with more votes than candidate i + x + 1 is less than m
    if (z < n - m)
        return false;
    // Ensure that even if all remaining votes go to candidate i, they would still win
    return (x + y + 1) * (z - n + m) > k - y;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int i, j, x, y, z, t;
    cin >> n >> m >> k;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        k -= a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for (i = 1; i <= n; i++)
        c[i] = c[i - 1] + b[i];
    
    for (i = 1; i <= n; i++) {
        // Binary search for the minimum additional votes needed
        int l = 0, r = k + 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(a[i], mid))
                r = mid;
            else
                l = mid + 1;
        }
        // If within constraints, print the result, otherwise print -1
        if (l <= k)
            cout << l << " ";
        else
            cout << "-1 ";
    }
    return 0;
}