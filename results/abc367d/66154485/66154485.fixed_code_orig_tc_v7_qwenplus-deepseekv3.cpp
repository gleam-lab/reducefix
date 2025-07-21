#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long prefix_sum = 0;
    vector<int> mod_count(m, 0);
    mod_count[0] = 1; // To account for prefix sums that are divisible by m themselves

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];
        int mod = (prefix_sum % m + m) % m; // Ensure mod is non-negative
        mod_count[mod]++;
    }

    long long ans = 0;
    for (int i = 0; i < m; i++) {
        if (mod_count[i] >= 2) {
            ans += (long long)mod_count[i] * (mod_count[i] - 1) / 2;
        }
    }

    cout << ans;
    return 0;
}