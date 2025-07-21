#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using LL = long long;

const int N = 1'000'007;

int main() {
    int n, m;
    cin >> n;
    vector<LL> a(n + 1), b(n + 1), c(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        c[i] = c[i - 1] + b[i];
    }
    
    cin >> m;
    while (m--) {
        LL l, r;
        cin >> l >> r;
        
        auto l_i = lower_bound(a.begin() + 1, a.end(), l) - a.begin();
        auto r_j = upper_bound(a.begin() + 1, a.end(), r) - a.begin();
        
        LL result;
        if (r >= a[n]) {
            result = c[n] - c[l_i - 1];
        } else {
            result = c[r_j - 1] - c[l_i - 1];
        }
        
        cout << result << endl;
    }
    
    return 0;
}