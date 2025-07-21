#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + nums[i];
    }
    
    unordered_map<int, int> mod_count;
    for (int i = 0; i <= n; ++i) {
        int mod = (prefix[i] % m + m) % m;
        mod_count[mod]++;
    }
    
    long long count = 0;
    for (const auto& pair : mod_count) {
        long long f = pair.second;
        count += f * (f - 1) / 2;
    }
    
    cout << count << endl;
    return 0;
}