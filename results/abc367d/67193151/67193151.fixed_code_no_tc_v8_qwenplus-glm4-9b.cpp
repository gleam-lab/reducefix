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
        // Copy the array to handle wrap-around for indices beyond n
        a[i + n] = a[i];
    }

    // Initialize prefix sum array
    b[0] = 1;
    for (i = 1; i <= 2 * n; i++) {
        // Calculate the index to decrement if i is within the first half
        if (i < n) {
            b[d[i - 1] % m]--;
        }

        // Update the prefix sum array
        d[i] = d[i - 1] + a[i];
        sum += b[d[i] % m];

        // Increment the count for the current value of d[i]
        cnt = (b[d[i] % m] = cnt + 1);

        // Calculate the index to increment if i is within the first half
        if (i < n) {
            b[d[i] % m]++;
        }
    }

    cout << sum;
    return 0;
}