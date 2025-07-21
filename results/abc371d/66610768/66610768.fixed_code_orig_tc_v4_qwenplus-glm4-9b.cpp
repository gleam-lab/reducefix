#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 1e6+7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n+1,0), b(n+1,0), c(n+1,0);
    
    // Read array a
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    // Read array b and compute prefix sums in c
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        c[i] = c[i-1] + b[i];
    }
    
    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        auto l_i = lower_bound(a.begin() + 1, a.end(), l);
        auto r_j = upper_bound(a.begin() + 1, a.end(), r);
        int i = l_i - a.begin();
        int j = r_j - a.begin();
        
        // Calculate the sum in array b from index i to j-1
        if (r >= a[n]) {
            cout << c[n] - (i > 0 ? (c[i-1] : 0)) << endl;
        } else {
            cout << (j > 0 ? (c[j-1] - (i > 0 ? (c[i-1] : 0))) : 0) << endl;
        }
    }
    
    return 0;
}