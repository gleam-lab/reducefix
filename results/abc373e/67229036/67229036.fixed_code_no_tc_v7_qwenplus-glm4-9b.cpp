#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, m, k, sum, cnt, a[N], b[N], c[N];
bool check(int x, int y) {
    int z = lower_bound(b + 1, b + 1 + n, x + y + 1) - b - 1;
    if (z < n - m) return 0;
    return (x + y + 1) * (z - n + m) - (c[z] - c[n - m - 1] - max(x, b[n - m])) > k - y;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum >= k) { // All votes already counted are greater than or equal to total votes
        for (int i = 1; i <= n; i++) cout << "0 ";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        b[i] = a[i];
        c[i] = c[i - 1] + a[i];
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        int votes_needed = 1;
        while (check(a[i], votes_needed)) {
            votes_needed++;
        }
        votes_needed--;
        if (votes_needed <= k - sum) {
            cout << votes_needed << " ";
        } else {
            cout << "-1 ";
        }
    }
    return 0;
}