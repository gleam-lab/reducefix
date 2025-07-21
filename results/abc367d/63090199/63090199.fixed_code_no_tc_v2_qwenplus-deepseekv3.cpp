#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = (prefix_sum[i] + nums[i]) % m;
    }
    
    unordered_map<long long, int> freq;
    for (int i = 0; i <= n; i++) {
        freq[prefix_sum[i]]++;
    }
    
    long long count = 0;
    for (auto &p : freq) {
        long long c = p.second;
        count += c * (c - 1) / 2;
    }
    
    cout << count << endl;
    return 0;
}