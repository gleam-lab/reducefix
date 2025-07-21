#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }

    unordered_map<int, int> mod_counts;
    mod_counts[0] = 1; // Empty prefix sum
    long long ans = 0;

    for (int i = 1; i <= n; i++) {
        int mod = (prefix[i] % m + m) % m;
        ans += mod_counts[mod];
        mod_counts[mod]++;
    }

    cout << ans << endl;
    return 0;
}