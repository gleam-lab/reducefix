#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int n, m;
long long a[N], prefix[N];
map<long long, long long> cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i]; // Duplicate the array for circular handling
    }

    // Compute prefix sums modulo m
    long long res = 0;
    cnt[0] = 1; // To count subarrays starting from index 0

    for (int i = 1; i < 2 * n; ++i) {
        prefix[i] = (prefix[i - 1] + a[i]) % m;
        res += cnt[prefix[i]];
        if (i < n) {
            cnt[prefix[i]]++; // Only increment before reaching the second loop
        }
    }

    cout << res << endl;
    return 0;
}