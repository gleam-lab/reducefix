#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> prefix_mod(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix_mod[i + 1] = (prefix_mod[i] + arr[i]) % m;
    }

    unordered_map<int, int> mod_count;
    for (int mod : prefix_mod) {
        mod_count[mod]++;
    }

    long long ans = 0;
    for (auto& [mod, cnt] : mod_count) {
        ans += (long long)cnt * (cnt - 1) / 2;
    }

    cout << ans;
    return 0;
}