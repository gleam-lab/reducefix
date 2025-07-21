#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, m, k, sum, cnt, a[N], b[N], c[N];

bool check(int x, int y) {
    // Find the number of candidates that have received more than x votes
    int z = lower_bound(b + 1, b + 1 + n, x + 1) - b - 1;
    // If there are less than m candidates with votes more than x, then x is a valid number
    if (z < m) return true;
    // Calculate the additional votes needed to ensure the victory
    long long additional_votes = (x + y + 1) * (z - m) - (c[z] - c[m - 1] - max(x, b[m - 1]));
    return additional_votes < k - y;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int i;
    cin >> n >> m >> k;
    for (i = 1; i <= n; i++)
        cin >> a[i], k -= a[i], b[i] = a[i];
    sort(b + 1, b + n + 1);
    for (i = 1; i <= n; i++)
        c[i] = c[i - 1] + b[i];
    for (i = 1; i <= n; i++) {
        // Binary search for the minimum additional votes needed
        int l = 0, r = k + 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(a[i], mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        // If l > k, it means the candidate cannot win even with all remaining votes
        cout << (l > k ? -1 : l) << " ";
    }
    return 0;
}