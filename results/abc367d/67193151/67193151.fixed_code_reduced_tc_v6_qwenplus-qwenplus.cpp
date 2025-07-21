#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, m, a[N * 2];
long long sum;
map<int, int> cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i]; // Duplicate array for circular handling
    }

    long long prefix = 0;
    cnt[0] = 1; // Initialize count of prefix sum mod m as 1 (for zero)

    for (int i = 1; i < 2 * n; ++i) {
        prefix += a[i];
        int mod = ((prefix % m) + m) % m; // Ensure non-negative mod

        // Exclude the part that is out of the sliding window of size n
        if (i > n) {
            long long prev_prefix = prefix - a[i - n];
            int prev_mod = ((prev_prefix % m) + m) % m;
            cnt[prev_mod]--;
        }

        sum += cnt[mod]; // Count occurrences of current mod
        cnt[mod]++; // Record current mod
    }

    cout << sum << endl;
    return 0;
}