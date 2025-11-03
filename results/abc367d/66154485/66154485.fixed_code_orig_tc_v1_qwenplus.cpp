#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] %= m;
    }
    
    long long ans = 0;
    
    // Count frequency of prefix sums modulo m
    map<int, int> count;
    count[0] = 1; // Empty prefix has sum 0
    
    int prefix = 0;
    for (int i = 0; i < n; i++) {
        prefix = (prefix + arr[i]) % m;
        ans += count[prefix];
        count[prefix]++;
    }
    
    cout << ans;
    return 0;
}