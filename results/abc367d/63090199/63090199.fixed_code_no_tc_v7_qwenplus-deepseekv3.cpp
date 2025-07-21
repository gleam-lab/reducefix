#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    vector<long long> prefix_mod(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix_mod[i] = (prefix_mod[i - 1] + nums[i - 1]) % m;
    }
    
    unordered_map<int, int> mod_count;
    long long count = 0;
    for (int i = 0; i <= n; i++) {
        int current_mod = prefix_mod[i];
        count += mod_count[current_mod];
        mod_count[current_mod]++;
    }
    
    cout << count << endl;
    return 0;
}