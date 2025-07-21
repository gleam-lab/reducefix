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

    vector<int> mod_count(m, 0);
    mod_count[0] = 1; // for prefix[0] which is 0

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int mod = prefix[i] % m;
        if (mod < 0) mod += m; // handle negative mod
        ans += mod_count[mod];
        mod_count[mod]++;
    }

    cout << ans;
    return 0;
}