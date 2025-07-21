#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    vector<int> prefixSum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixSum[i + 1] = (prefixSum[i] + nums[i]) % m;
    }
    
    unordered_map<int, int> remainderCount;
    for (int i = 0; i <= n; i++) {
        remainderCount[prefixSum[i]]++;
    }
    
    long long count = 0;
    for (auto& entry : remainderCount) {
        long long c = entry.second;
        count += c * (c - 1) / 2;
    }
    
    cout << count << endl;
    return 0;
}