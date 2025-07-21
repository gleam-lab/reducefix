#include<bits/stdc++.h>
using namespace std;
int n, m;
int main(){
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = (prefix_sum[i] + nums[i]) % m;
    }
    unordered_map<int, long long> mod_count;
    for (int i = 0; i <= n; i++) {
        mod_count[prefix_sum[i]]++;
    }
    long long count = 0;
    for (auto& pair : mod_count) {
        long long c = pair.second;
        count += c * (c - 1) / 2;
    }
    cout << count << endl;
    return 0;
}