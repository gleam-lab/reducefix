#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
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
        
        // Find first element >= l
        auto l_it = lower_bound(a.begin()+1, a.end(), l);
        int i = l_it - a.begin();
        
        // Find first element > r
        auto r_it = upper_bound(a.begin()+1, a.end(), r);
        int j = r_it - a.begin();
        
        if(i > n) {
            // No elements >= l
            cout << 0 << endl;
        } else if(r < a[1]) {
            // All elements > r
            cout << 0 << endl;
        } else {
            // Calculate sum between i and j-1
            cout << c[j-1] - c[i-1] << endl;
        }
    }
    return 0;
}