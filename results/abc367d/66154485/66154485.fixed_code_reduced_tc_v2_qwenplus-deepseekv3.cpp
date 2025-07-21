#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = (prefix[i] + arr[i]) % m;
    }
    
    long long ans = 0;
    unordered_map<int, int> count;
    count[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        ans += count[prefix[i]];
        count[prefix[i]]++;
    }
    
    cout << ans;
    return 0;
}