#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(2 * n + 1);
    vector<int> t(m, 0);
    long long an = 0;
    vector<int> w(2 * n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }

    // Compute prefix sums modulo m
    for (int i = 1; i <= 2 * n; i++) {
        w[i] = (w[i-1] + a[i]) % m;
    }

    // Count empty subarrays at position 0
    t[0] = 1;

    for (int i = 1; i <= 2 * n; i++) {
        // Add number of previous occurrences with same prefix sum
        if (i <= n) {
            an += t[w[i]];
            t[w[i]]++;
        } else {
            // When i > n, we need to remove the contribution from position i-n
            t[w[i - n]]--;
            an += t[w[i]];
            t[w[i]]++;
        }
    }

    cout << an;
    return 0;
}