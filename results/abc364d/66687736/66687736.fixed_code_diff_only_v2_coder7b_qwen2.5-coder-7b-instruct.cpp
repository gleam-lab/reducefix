#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    for(int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        
        auto it = lower_bound(a.begin(), a.end(), b);
        int index = it - a.begin();
        
        if(k <= index + 1) {
            cout << abs(a[index] - b) << '\n';
        } else {
            cout << abs(a[min(index + k - 1, n - 1)] - b) << '\n';
        }
    }
    
    return 0;
}