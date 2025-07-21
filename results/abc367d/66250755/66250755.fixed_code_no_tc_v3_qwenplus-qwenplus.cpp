#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(2 * n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }

    // Prefix sum mod m
    vector<int> prefix(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; ++i) {
        prefix[i] = (prefix[i - 1] + a[i]) % m;
    }

    // Use a map to count occurrences of each mod value
    map<int, int> count;
    count[0] = n;  // Important: There are n positions where prefix[i-n] can be (for i >= n)
    long long ans = 0;

    for (int i = n; i <= 2 * n; ++i) {
        // Remove the count that goes out of window
        if (i > n) {
            count[prefix[i - n]]--;
        }
        // Add current prefix mod m to answer
        ans += count[prefix[i]];
        // Increase count for current prefix
        count[prefix[i]]++;
    }

    cout << ans << endl;
    return 0;
}