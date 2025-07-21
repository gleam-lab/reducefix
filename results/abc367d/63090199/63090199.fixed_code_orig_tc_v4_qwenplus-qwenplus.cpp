#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // Use a map to count the frequency of each prefix sum modulo m
    unordered_map<int, long long> mod_count;
    long long count = 0;
    long long prefix_sum = 0;

    // Initially, there is one prefix sum (empty prefix) with value 0
    mod_count[0] = 1;

    for (int i = 0; i < n; ++i) {
        prefix_sum = (prefix_sum + nums[i]) % m;
        // If this mod has been seen before, all subarrays between previous indices and current index are valid
        count += mod_count[prefix_sum];
        mod_count[prefix_sum]++;
    }

    cout << count << endl;
    return 0;
}