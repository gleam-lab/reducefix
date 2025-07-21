#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e6 + 5;

int n, m;
ll a[N], prefix[N];
map<int, int> cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Extend array to handle circular property
    for (int i = 0; i < n; ++i) {
        a[i + n] = a[i];
    }

    // Compute prefix sums mod m
    prefix[0] = 0;
    cnt[0] = 1; // To count subarrays starting from index 0
    ll total = 0;

    for (int i = 1; i < 2 * n; ++i) {
        prefix[i] = (prefix[i - 1] + a[i - 1]) % m;

        // Count how many times this mod value has been seen before
        total += cnt[prefix[i]];

        // Update the count of this mod value
        cnt[prefix[i]]++;

        // If we've passed the first n elements, remove the counts that are now out of window
        if (i >= n) {
            cnt[prefix[i - n]]--;
        }
    }

    cout << total << "\n";

    return 0;
}