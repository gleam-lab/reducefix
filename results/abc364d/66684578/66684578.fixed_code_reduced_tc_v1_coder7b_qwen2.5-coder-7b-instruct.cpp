#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<long long> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    for(int j = 0; j < q; ++j) {
        long long b, k;
        cin >> b >> k;
        
        auto it = lower_bound(a.begin(), a.end(), b);
        int index = it - a.begin();
        
        long long leftDist = (index == 0) ? abs(b - a[0]) : abs(b - a[index - 1]);
        long long rightDist = (index == n - 1) ? abs(b - a[n - 1]) : abs(b - a[index]);
        
        if(k == 1) {
            cout << min(leftDist, rightDist) << '\n';
        } else if(k == n) {
            cout << max(leftDist, rightDist) << '\n';
        } else {
            cout << abs(b - a[index + k - 1]) << '\n';
        }
    }
    
    return 0;
}