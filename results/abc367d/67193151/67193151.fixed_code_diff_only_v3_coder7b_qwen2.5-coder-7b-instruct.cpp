#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, k, sum, cnt, a[N], b[N], d[N];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int i, j, x, y, z, t;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i]; // Duplicate array to handle circular nature
    }
    memset(b, 0, sizeof(b)); // Initialize frequency array
    b[0] = 1; // Base case: remainder 0 occurs once
    for (i = 1; i < n * 2; i++) {
        if (i >= n) {
            b[d[i - n] % m]--; // Decrement count of previous remainder
        }
        d[i] = d[i - 1] + a[i]; // Update prefix sum
        sum += b[d[i] % m]; // Add count of current remainder to sum
        if (i < n) {
            b[d[i] % m]++; // Increment count of current remainder
        }
    }
    cout << sum << endl;
    return 0;
}