#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int n, m;
long long a[N];
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

    long long sum = 0;
    long long prefix_sum = 0;
    cnt[0] = 1; // Initialize with 0 remainder

    for (int i = 1; i < 2 * n; ++i) {
        prefix_sum += a[i];
        long long rem = prefix_sum % m;

        // Count how many times this remainder has occurred before
        sum += cnt[rem];

        // Increment the count of this remainder only if it's within the first n elements
        if (i < n) {
            cnt[rem]++;
        } else {
            // Remove the contribution of the element that is now out of window
            long long rem_out = (prefix_sum - a[i - n + 1]) % m;
            cnt[rem_out]--;
            if (cnt[rem_out] == 0) {
                cnt.erase(rem_out);
            }
        }
    }

    cout << sum << endl;
    return 0;
}