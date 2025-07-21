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
    
    sort(num.begin(), num.end());
    
    // Calculate the number of elements to remove from each end
    int del = k / 2;
    int md = k % 2;
    
    // If k is odd, we need to remove one more element to balance it out
    if (md != 0) {
        int ans = min(num[del] - num[n - del - 1], num[del - 1] - num[n - del]);
        cout << ans << endl;
    } else {
        cout << num[del] - num[n - del - 1] << endl;
    }
    
    return 0;
}