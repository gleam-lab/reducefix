#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

int n, m;
long long a[N];
map<int, int> cnt;
long long sum = 0;
long long prefix_sum = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];  // Duplicate array for circular handling
    }

    cnt[0] = 1;  // Initialize count of prefix sum mod m as 0

    for (int i = 1; i < 2 * n; ++i) {
        prefix_sum += a[i];
        int mod = (prefix_sum % m + m) % m;  // Ensure non-negative mod

        // Subtract the counts that are out of the sliding window of size n
        if (i >= n) {
            int prev_mod = (prefix_sum - a[i - n] * 1LL) % m;
            cnt[prev_mod]--;
            prefix_sum -= a[i - n];
        }

        sum += cnt[mod];
        cnt[mod]++;
    }

    cout << sum << endl;
    return 0;
}