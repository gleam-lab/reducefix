#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> prefix_mod(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix_mod[i + 1] = (prefix_mod[i] + nums[i]) % m;
    }

    unordered_map<int, int> mod_count;
    for (int i = 0; i <= n; i++) {
        mod_count[prefix_mod[i]]++;
    }

    long long count = 0;
    for (auto& [mod, cnt] : mod_count) {
        count += (long long)cnt * (cnt - 1) / 2;
    }

    cout << count << endl;
    return 0;
}