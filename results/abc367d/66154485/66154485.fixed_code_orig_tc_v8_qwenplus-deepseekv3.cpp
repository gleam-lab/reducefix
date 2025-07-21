#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    vector<int> prefix_mod(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_mod[i + 1] = (prefix_mod[i] + arr[i]) % m;
    }
    
    unordered_map<int, int> mod_count;
    long long ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans += mod_count[prefix_mod[i]];
        mod_count[prefix_mod[i]]++;
    }
    
    cout << ans << '\n';
    return 0;
}