#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005];
map<int, int>sum;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        sum[x[i]] = p[i];
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int l = lower_bound(x + 1, x + n + 1, L) - x;
        int r = upper_bound(x + 1, x + n + 1, R) - x;
        // Calculate the sum of the prefix sums from l+1 to r-1
        int result = sum[x[r-1]];
        if (l > 1) {
            result -= sum[x[l-1]];
        }
        cout << result << endl;
    }
    return 0;
}