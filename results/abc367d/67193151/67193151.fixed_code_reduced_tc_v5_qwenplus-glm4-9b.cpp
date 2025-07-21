#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, k, sum, cnt, a[N], b[N], d[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Initialize b array to count occurrences of each number modulo m
    for (int i = 0; i < m; i++) {
        b[i] = 0;
    }

    // Count initial occurrences
    for (int i = 1; i <= n; i++) {
        int modValue = a[i] % m;
        b[modValue]++;
    }

    // Calculate the sum based on the transformations
    sum = 0;
    for (int i = 0; i < 2 * n; i++) {
        int modValue = (i < n) ? (a[i] % m) : ((a[i - n] + d[i - 1]) % m);
        sum += b[modValue];
        if (i < n) {
            b[modValue]--;
        } else if (i >= n) {
            int nextModValue = (a[i + 1] % m);
            b[nextModValue]++;
        }
    }

    cout << sum;
    return 0;
}