#include<bits/stdc++.h>
using namespace std;

int n, m;
int main() {
    cin >> n >> m;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    
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
    unordered_map<int, int> remainder_count;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int remainder = (prefixsum[j] - prefixsum[i]) % m;
            if (remainder < 0) remainder += m;  // Make sure remainder is positive
            remainder_count[remainder]++;
        }
    }
    
    // Count valid pairs
    for (auto& elem : remainder_count) {
        int rem = elem.first;
        int count1 = elem.second;
        int count2 = remainder_count[(rem + m / 2) % m]; // Check the complementary remainder
        count += count1 * count2;
    }
    
    cout << count / 2 << endl; // Each pair is counted twice, once for each order
    
    return 0;
}