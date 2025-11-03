#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long ans = 0;
    vector<int> prefix_mod(m, 0);
    prefix_mod[0] = 1; // Empty prefix has mod 0

    long long prefix_sum = 0;
    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];
        int mod = ((prefix_sum % m) + m) % m; // Handle negative mods
        ans += prefix_mod[mod];
        prefix_mod[mod]++;
    }

    cout << ans;
    return 0;
}