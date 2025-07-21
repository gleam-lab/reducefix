#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, m, k, sum, cnt, a[N], b[N], d[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];  // Extend the array
    }
    b[0] = 1;
    for (int i = 1; i < n * 2; ++i) {
        if (i >= n) {
            b[d[i - n] % m]--;  // Decrement the count of the old prefix sum modulo m
        }
        d[i] = d[i - 1] + a[i];  // Compute the new prefix sum
        sum += b[d[i] % m];  // Add the count of the new prefix sum modulo m to the sum
        if (i < n) {
            b[d[i] % m]++;  // Increment the count of the new prefix sum modulo m
        }
    }
    cout << sum;
    return 0;
}