#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        unordered_map<int, int> prefix_sum_count;
        prefix_sum_count[0] = 1;
        
        for (int j = 1; j <= n; ++j) {
            sum = (sum + arr[(i + j - 1) % n]) % m;
            ans = (ans + prefix_sum_count[(sum * m - j + m) % m]) % MOD;
            prefix_sum_count[sum]++;
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}