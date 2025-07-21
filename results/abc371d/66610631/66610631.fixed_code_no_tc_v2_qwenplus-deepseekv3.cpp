#include<bits/stdc++.h>
using namespace std;
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
        
        // Find first element >= l
        auto l_it = lower_bound(a.begin()+1, a.end(), l);
        int l_idx = l_it - a.begin();
        
        // Find first element > r
        auto r_it = upper_bound(a.begin()+1, a.end(), r);
        int r_idx = r_it - a.begin() - 1;
        
        if(l_it == a.end()) {
            // All elements are smaller than l
            cout << 0 << endl;
        }
        else if(r_it == a.begin()+1) {
            // All elements are larger than r
            cout << 0 << endl;
        }
        else {
            if(l_idx > r_idx) {
                cout << 0 << endl;
            }
            else {
                cout << c[r_idx] - c[l_idx-1] << endl;
            }
        }
    }
    return 0;
}