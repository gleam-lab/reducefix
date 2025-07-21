#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int n, m, a[N];
long long prefix_sum = 0, total = 0;
map<long long, long long> cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[n + i] = a[i]; // Duplicate the array for circular handling
    }

    cnt[0] = 1; // Initialize count of prefix sums mod m

    for (int i = 1; i < 2 * n; ++i) {
        prefix_sum += a[i];
        long long mod = prefix_sum % m;

        // Subtract contributions from the part that's out of window
        if (i > n) {
            long long old_mod = (prefix_sum - a[i - n]) % m;
            cnt[old_mod]--;
        }

        // Count how many previous prefix sums equal to current mod
        total += cnt[mod];

        // Add current mod to map only if it's in the first n elements
        if (i < n) {
            cnt[mod]++;
        }
    }

    cout << total << "\n";
    return 0;
}