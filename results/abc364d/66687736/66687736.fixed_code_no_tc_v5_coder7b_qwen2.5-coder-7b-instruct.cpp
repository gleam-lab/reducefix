#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<long long> a(n), b(q);
    vector<int> k(q);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 0; i < q; ++i) {
        cin >> b[i] >> k[i];
    }
    
    sort(a.begin(), a.end());
    
    for (int i = 0; i < q; ++i) {
        auto it = lower_bound(a.begin(), a.end(), b[i]);
        int pos = it - a.begin();
        
        if (pos == 0) {
            cout << abs(a[0] - b[i]) << '\n';
        } else if (pos == n) {
            cout << abs(a[n-1] - b[i]) << '\n';
        } else {
            int leftDist = abs(a[pos] - b[i]);
            int rightDist = abs(a[pos-1] - b[i]);
            
            if (k[i] <= leftDist) {
                cout << leftDist << '\n';
            } else {
                cout << rightDist << '\n';
            }
        }
    }
    
    return 0;
}