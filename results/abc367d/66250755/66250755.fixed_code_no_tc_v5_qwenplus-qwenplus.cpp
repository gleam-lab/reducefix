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
    vector<int> prefix(2 * n + 1);
    for (int i = 1; i <= 2 * n; ++i) {
        prefix[i] = (prefix[i - 1] + a[i]) % m;
    }

    // Use a map to count occurrences of each mod value
    map<int, int> count;
    int result = 0;

    for (int i = n; i >= 1; --i) {
        // We are considering subarrays ending at i
        // So we want to count how many previous prefixes have prefix[j] == prefix[i]
        // which would mean prefix[i] - prefix[j] == 0 mod m
        result += count[prefix[i]];
        count[prefix[i]]++;

        // Only keep the first n prefixes in the map
        if (i > n) {
            count[prefix[i]]--;
        }
    }

    cout << result << endl;
    return 0;
}