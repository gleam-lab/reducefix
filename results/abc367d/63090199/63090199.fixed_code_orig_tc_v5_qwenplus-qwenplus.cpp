#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // Map to count occurrences of each prefix sum modulo m
    unordered_map<int, int> mod_count;
    long long prefix_sum = 0;
    long long count = 0;

    // Initially, there is one prefix (empty) with mod 0
    mod_count[0] = 1;

    for (int i = 0; i < n; ++i) {
        prefix_sum = (prefix_sum + nums[i]) % m;
        // If this mod has been seen before, add the number of times it was seen
        if (mod_count.find(prefix_sum) != mod_count.end()) {
            count += mod_count[prefix_sum];
        }
        // Increment the count for current mod value
        mod_count[prefix_sum]++;
    }

    cout << count << endl;
    return 0;
}