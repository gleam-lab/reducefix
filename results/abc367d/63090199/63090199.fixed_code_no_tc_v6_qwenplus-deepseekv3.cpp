#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    long long total_sum = prefix[n];
    long long count = 0;

    // Frequency map for prefix sums mod m
    unordered_map<int, int> freq;
    freq[0] = 1; // To handle cases where prefix[i] mod m == 0

    for (int i = 1; i <= n; i++) {
        int mod = (prefix[i] % m + m) % m; // Ensure positive mod
        count += freq[mod];
        freq[mod]++;
    }

    // Reset frequency map for circular cases
    freq.clear();
    freq[0] = 1; // To handle cases where (prefix[i] + total_sum) mod m == 0

    for (int i = 1; i <= n; i++) {
        int mod = ((prefix[i] + total_sum) % m + m) % m;
        count += freq[mod];
        freq[mod]++;
    }

    // Subtract the cases where s == t (since s != t is required)
    count -= n;

    cout << count << endl;
    return 0;
}