#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n+1, 0), b(n+1, 0);
    vector<ll> c(n+1, 0); // Use long long for prefix sums
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        c[i] = c[i-1] + b[i]; // Compute prefix sums
    }
    
    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        
        auto l_it = lower_bound(a.begin()+1, a.end(), l);
        auto r_it = upper_bound(a.begin()+1, a.end(), r);
        
        int i = l_it - a.begin();
        int j = r_it - a.begin();
        
        // Handle cases where r is beyond the last element
        if(r >= a[n]) {
            cout << c[n] - c[i-1] << endl;
        } else {
            cout << c[j-1] - c[i-1] << endl;
        }
    }
    return 0;
}