#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

int main() {
    int n, m;
    cin >> n;
    vector<ll> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        c[i] = c[i - 1] + b[i];
    }
    
    cin >> m;
    while (m--) {
        ll l, r;
        cin >> l >> r;
        
        // Use lower_bound and upper_bound with correct type casting
        auto l_i = lower_bound(a.begin() + 1, a.end(), l) - a.begin();
        auto r_j = upper_bound(a.begin() + 1, a.end(), r) - a.begin();
        
        // Handle edge cases where r is greater than the maximum value in array a
        if (r >= *max_element(a.begin() + 1, a.end())) {
            cout << c[n] - c[l_i - 1] << endl;
        } else {
            cout << c[r_j - 1] - c[l_i - 1] << endl;
        }
    }
    
    return 0;
}