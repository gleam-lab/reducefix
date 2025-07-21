#include<bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Compute prefix sums mod m
    vector<int> prefix_mod(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix_mod[i] = (prefix_mod[i - 1] + nums[i - 1]) % m;
    }

    // Use a map to count occurrences of each remainder
    map<int, int> mod_count;
    mod_count[0] = 1;  // Initialize with prefix_mod[0]

    long long count = 0;
    for (int i = 1; i <= n; i++) {
        // We want to find how many previous prefixes have the same mod value
        // Because (prefix[i] - prefix[j]) % m == 0 means prefix[i] % m == prefix[j] % m
        count += mod_count[prefix_mod[i]];
        mod_count[prefix_mod[i]]++;
    }

    cout << count << endl;
    return 0;
}