#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n;
    vector<int> a(n+1, 0), b(n+1, 0), c(n+1, 0);
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        c[i] = b[i] + c[i-1];
    }
    
    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        
        // Find first a[i] >= l
        auto it_l = lower_bound(a.begin()+1, a.end(), l);
        int i = it_l - a.begin();
        
        // Find first a[j] > r
        auto it_r = upper_bound(a.begin()+1, a.end(), r);
        int j = it_r - a.begin();
        
        if(i > n) {
            // All elements are smaller than l
            cout << 0 << '\n';
        } else if(j <= 1) {
            // All elements are larger than r
            cout << 0 << '\n';
        } else {
            // Calculate sum from i to j-1
            cout << c[j-1] - c[i-1] << '\n';
        }
    }
    
    return 0;
}