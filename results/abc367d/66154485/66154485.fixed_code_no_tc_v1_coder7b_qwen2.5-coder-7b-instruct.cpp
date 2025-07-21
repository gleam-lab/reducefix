#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Calculate prefix sums modulo m
    vector<int> prefix_sum_mod_m(m);
    for (int i = 0; i < n; i++) {
        prefix_sum_mod_m[arr[i] % m]++;
    }

    // Count valid pairs using prefix sums
    for (int i = 0; i < m; i++) {
        if (prefix_sum_mod_m[i] > 1) {
            ans += prefix_sum_mod_m[i] * (prefix_sum_mod_m[i] - 1) / 2;
        }
    }

    cout << ans;
    return 0;
}