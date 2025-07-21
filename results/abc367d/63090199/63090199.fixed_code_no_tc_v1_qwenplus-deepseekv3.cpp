#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = (prefix[i] + nums[i]) % m;
    }

    long long total_sum = prefix[n];
    long long count = 0;
    unordered_map<int, int> mod_count;

    for (int i = 0; i <= n; i++) {
        int current_mod = prefix[i];
        count += mod_count[current_mod];
        mod_count[current_mod]++;
    }

    cout << count << endl;
    return 0;
}