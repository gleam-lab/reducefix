#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Prefix sum and modulo count
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = (prefix[i] + arr[i]) % m;
    }

    // Count occurrences of each modulo
    unordered_map<int, int> mod_count;
    long long ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += mod_count[prefix[i]];
        mod_count[prefix[i]]++;
    }

    cout << ans;
    return 0;
}