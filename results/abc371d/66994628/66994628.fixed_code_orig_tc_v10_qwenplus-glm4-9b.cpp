#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
long long x[MAXN], p[MAXN], sum[MAXN];

int main() {
    int n, q;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &x[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &p[i]);
        sum[i] = sum[i-1] + p[i];
    }
    
    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);

        // Adjust for 1-based index
        l = upper_bound(x + 1, x + n + 1, l) - (x + 1);
        r = upper_bound(x + 1, x + n + 1, r) - (x + 1);

        // Output the sum from index l to r-1
        cout << sum[r-1] - sum[l-1] << endl;
    }

    return 0;
}