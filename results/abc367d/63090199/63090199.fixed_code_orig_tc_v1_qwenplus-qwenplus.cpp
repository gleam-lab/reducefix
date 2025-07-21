#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // To count prefix sums modulo m
    vector<long long> mod_count(m, 0);

    long long prefix_sum = 0;
    long long result = 0;

    // We include the prefix sum of 0 at the beginning
    mod_count[0] = 1;

    for (int i = 0; i < n; ++i) {
        prefix_sum += nums[i];
        // Ensure the prefix_sum is kept within modulo m range
        int mod = ((prefix_sum % m) + m) % m; // handle negative values
        result += mod_count[mod];
        mod_count[mod]++;
    }

    cout << result << endl;
    return 0;
}