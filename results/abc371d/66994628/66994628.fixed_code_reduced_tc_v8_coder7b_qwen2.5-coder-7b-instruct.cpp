#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, q, x[MAXN], p[MAXN];
long long sum[MAXN];

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
        int l, r;
        cin >> l >> r;
        // Adjusting indices because array is 1-indexed in problem statement but 0-indexed in implementation
        l++;
        r++;
        l = lower_bound(x + 1, x + n + 1, l) - x;
        r = upper_bound(x + 1, x + n + 1, r) - x;
        cout << sum[r - 1] - sum[l - 1] << endl;
    }
    return 0;
}