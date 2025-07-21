#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> mod_counts(m, 0);
    mod_counts[0] = 1; // empty prefix sum
    long long prefix = 0;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        prefix += arr[i];
        int mod = (prefix % m + m) % m; // handle negative numbers
        ans += mod_counts[mod];
        mod_counts[mod]++;
    }

    cout << ans;
    return 0;
}