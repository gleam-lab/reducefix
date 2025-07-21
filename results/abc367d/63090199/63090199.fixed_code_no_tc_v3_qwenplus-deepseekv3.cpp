#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> prefix_mod(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_mod[i + 1] = (prefix_mod[i] + nums[i]) % m;
    }

    unordered_map<int, int> mod_count;
    long long result = 0;
    for (int i = 0; i <= n; ++i) {
        result += mod_count[prefix_mod[i]];
        mod_count[prefix_mod[i]]++;
    }

    cout << result << endl;
    return 0;
}