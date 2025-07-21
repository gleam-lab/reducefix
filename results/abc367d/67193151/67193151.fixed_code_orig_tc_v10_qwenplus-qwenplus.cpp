#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

int n, m;
long long a[N], prefix[N];
map<int, int> cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];  // Duplicate array for circular handling
    }

    // Compute prefix sums modulo m
    for (int i = 1; i <= 2 * n; ++i) {
        prefix[i] = (prefix[i - 1] + a[i]) % m;
    }

    long long res = 0;
    cnt[0] = 1;  // Initialize count of mod 0

    for (int i = 1; i <= 2 * n; ++i) {
        res += cnt[prefix[i]];
        if (i <= n) {
            cnt[prefix[i]]++;
        } else {
            // Remove the count that's out of the sliding window of size n
            cnt[prefix[i - n]]--;
        }
    }

    cout << res << endl;
    return 0;
}