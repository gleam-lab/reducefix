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
    vector<int> prefix_sum_mod(m, 0);
    prefix_sum_mod[arr[0] % m]++;
    int current_sum = arr[0];

    for (int i = 1; i < n; i++) {
        current_sum = (current_sum + arr[i]) % m;
        prefix_sum_mod[current_sum]++;
    }

    // Count valid subarrays
    for (int i = 0; i < m; i++) {
        if (prefix_sum_mod[i] > 1) {
            ans += prefix_sum_mod[i] * (prefix_sum_mod[i] - 1) / 2;
        }
    }

    cout << ans << endl;
    return 0;
}