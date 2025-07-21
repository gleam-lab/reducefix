#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

int main() {
    int n, m;
    cin >> n;
    vector<ll> a(n), b(n), c(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        c[i + 1] = c[i] + b[i];
    }
    
    sort(a.begin(), a.end());
    
    cin >> m;
    while (m--) {
        ll l, r;
        cin >> l >> r;
        
        auto l_i = lower_bound(a.begin(), a.end(), l);
        auto r_j = upper_bound(a.begin(), a.end(), r);
        
        int i = l_i - a.begin();
        int j = r_j - a.begin();
        
        // If r is greater than the maximum value in a, use the last element in c
        if (r >= a.back()) {
            cout << c[n] - c[i] << endl;
        } else {
            cout << c[j] - c[i] << endl;
        }
    }
    
    return 0;
}