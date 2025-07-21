#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<long long> nums(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
        nums[i] += nums[i - 1]; // Prefix sum array starting from index 1
    }
    
    long long count = 0;
    unordered_map<int, int> remainder_count;
    remainder_count[0] = 1; // To handle cases where the segment itself is divisible by m
    
    for (int i = 1; i <= n; ++i) {
        int remainder = nums[i] % m;
        count += remainder_count[(m - remainder) % m];
        remainder_count[remainder]++;
    }
    
    cout << count << endl;
    return 0;
}