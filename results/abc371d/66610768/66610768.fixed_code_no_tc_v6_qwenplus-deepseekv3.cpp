#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 1e6+7;

int main() {
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
        
        // Find the first a[i] >= l
        auto l_i = lower_bound(a.begin()+1, a.end(), l);
        int i = l_i - a.begin();
        
        // Find the first a[j] > r
        auto r_j = upper_bound(a.begin()+1, a.end(), r);
        int j = r_j - a.begin();
        
        // Ensure i is within bounds (<=n)
        if(i > n) {
            cout << 0 << endl;
            continue;
        }
        
        // Ensure j-1 is within bounds (>=1)
        if(j-1 < 1) {
            cout << 0 << endl;
            continue;
        }
        
        // Calculate the sum from i to min(j-1, n)
        cout << c[min(j-1, n)] - c[i-1] << endl;
    }
    return 0;
}