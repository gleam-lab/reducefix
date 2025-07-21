#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q;
int x[200005], p[200005];
ll sum[200005]; // Using long long to prevent overflow

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i-1] + p[i]; // Summing up with long long
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int left = lower_bound(x + 1, x + n + 1, l) - x;
        int right = upper_bound(x + 1, x + n + 1, r) - x;
        cout << sum[right - 1] - sum[left - 1] << endl;
    }
    return 0;
}