#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + arr[i];
    }

    unordered_map<int, int> mod_map;
    for (int i = 0; i <= n; ++i) {
        mod_map[(prefix[i] % m + m) % m]++;
    }

    long long ans = 0;
    for (const auto& pair : mod_map) {
        long long cnt = pair.second;
        ans += cnt * (cnt - 1) / 2;
    }

    cout << ans << endl;
    return 0;
}