#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n), b(n - 1);
    
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n - 1; ++i) cin >> b[i];
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int i = n - 1, j = n - 2, ans = INT_MAX;
    
    while(i >= 0 && j >= 0) {
        if(a[i] <= b[j]) {
            ans = min(ans, b[j]);
            --i;
        } else {
            --j;
        }
    }
    
    if(ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;
    
    return 0;
}