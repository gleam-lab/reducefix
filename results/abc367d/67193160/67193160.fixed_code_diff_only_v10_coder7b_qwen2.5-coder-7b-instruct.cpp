#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, k, sum, cnt, a[N], b[N], d[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i, j, x, y, z, t;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i]; // Ensure array is doubled to handle circular nature
    }
    b[0] = 1; // Initialize base case for prefix sum modulo count
    for (i = 1; i < n * 2; i++) {
        if (i >= n) {
            b[d[i - n] % m]--; // Decrease count of previous prefix sum modulo m
        }
        d[i] = d[i - 1] + a[i]; // Update current prefix sum
        sum += b[d[i] % m]; // Add count of current prefix sum modulo m to sum
        if (i < n) {
            b[d[i] % m]++; // Increase count of current prefix sum modulo m
        }
    }
    cout << sum;
    return 0;
}