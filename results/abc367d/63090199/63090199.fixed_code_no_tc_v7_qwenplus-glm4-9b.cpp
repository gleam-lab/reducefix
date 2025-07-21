#include<bits/stdc++.h>
using namespace std;
int n, m;
int main() {
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<long long> prefixsum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixsum[i + 1] = prefixsum[i] + nums[i];
    }
    int count = 0;
    // Use a map to store the frequency of remainders
    map<int, int> remainder_count[(m + 1) % m];
    
    // Calculate the number of valid (s, t) pairs
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            long long diff = j < i ? prefixsum[j] - prefixsum[i] : prefixsum[n] - prefixsum[i] + prefixsum[j];
            if (diff % m == 0) {
                count++;
            } else {
                remainder_count[diff % m][diff / m]++;
            }
        }
    }
    
    // Calculate the number of valid pairs using the remainder counts
    for (auto& p : remainder_count) {
        for (auto& q : p.second) {
            if (q > 1) {
                count += q * (q - 1) / 2;
            }
        }
    }
    
    cout << count << endl;
    return 0;
}