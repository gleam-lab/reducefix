#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
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

    unordered_map<int, int> mod_count;
    mod_count[0] = 1;
    long long ans = 0;

    for (int i = 1; i <= n; i++) {
        int mod = (prefix[i] % m + m) % m;
        ans += mod_count[mod];
        mod_count[mod]++;
    }

    cout << ans << '\n';
    return 0;
}