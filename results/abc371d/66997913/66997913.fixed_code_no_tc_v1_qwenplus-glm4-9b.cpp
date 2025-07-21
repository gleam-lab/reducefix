#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    vector<ll> p(n), s(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        s[i + 1] = s[i] + p[i];
    }
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        // Finding the position of r and l in the vector x
        int rt = upper_bound(x.begin(), x.end(), r) - x.begin() - 1; // Subtracting 1 to convert to 0-based index
        int lt = lower_bound(x.begin(), x.end(), l) - x.begin(); // This gives the first element greater or equal to l, hence no -1 needed
        
        // Calculate the sum from l to r using the prefix sums
        ll ans = (rt == -1) ? 0 : s[rt + 1] - s[lt];
        cout << ans << endl;
    }
    return 0;
}