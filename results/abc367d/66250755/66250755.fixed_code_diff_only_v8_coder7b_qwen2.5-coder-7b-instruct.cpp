#include<bits/stdc++.h>
using namespace std;

int n, m, a[400005], t[1000005], an, w[400005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[n + i] = a[i]; // Correctly assign values to avoid out-of-bound access
    }
    for (int i = 1; i < 2 * n; i++) {
        w[i + 1] = (w[i] + a[i]) % m;
        if (i > n) t[w[i - n]]--; // Correctly decrement the count of previous window sum
        if (i >= n) {
            an += t[w[i]]; // Accumulate the number of valid subarrays ending at current position
        }
        t[w[i]]++; // Increment the count of current window sum
    }
    cout << an;
    return 0;
}