#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    
    // Sort the array to easily pick the smallest and largest elements
    sort(num.begin(), num.end());
    
    // Calculate the minimum possible value of the difference
    int ans = num[k - 1] - num[0];
    if (k % 2 == 0) {
        ans = min(ans, num[n - k] - num[k]);
    } else {
        ans = min(ans, num[n - k - 1] - num[k]);
    }
    
    cout << ans << endl;
    
    return 0;
}