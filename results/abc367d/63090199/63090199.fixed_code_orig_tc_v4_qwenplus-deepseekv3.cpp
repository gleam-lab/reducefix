#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> prefix(n + 1, 0);
    for(int i = 0; i < n; i++) {
        prefix[i + 1] = (prefix[i] + nums[i]) % m;
    }

    unordered_map<int, int> mod_count;
    for(int i = 0; i <= n; i++) {
        mod_count[prefix[i]]++;
    }

    long long count = 0;
    for(auto& p : mod_count) {
        long long c = p.second;
        count += c * (c - 1) / 2;
    }

    cout << count << endl;
    return 0;
}