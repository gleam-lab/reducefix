#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    for(int i = 0; i < n; ++i) cin >> num[i];
    
    // Sort the array to easily find the minimum and maximum values after removal
    sort(num.begin(), num.end());
    
    // Calculate the minimum possible difference between the maximum and minimum values of the new sequence
    int ans = INT_MAX;
    for(int i = 0; i <= n-k; ++i) {
        ans = min(ans, num[i+k-1] - num[i]);
    }
    
    // Output the result
    cout << ans << '\n';
    return 0;
}