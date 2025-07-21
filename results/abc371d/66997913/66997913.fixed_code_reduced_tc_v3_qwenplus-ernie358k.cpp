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
    vector<ll> p(n), s(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        s[i + 1] = s[i] + p[i];
    }
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        // Use binary search to find the correct positions in x
        auto it_r = upper_bound(x.begin(), x.end(), r); // Find the first position greater than r
        auto it_l = lower_bound(x.begin(), it_r, l);   // Find the first position >= l within the range [begin, it_r)
        int rt = it_r - x.begin();
        int lt = it_l - x.begin();
        
        // Since we used upper_bound for r, rt points to one past the largest index <= r
        // Adjust rt to be the largest index <= r
        rt--;
        if (lt <= rt) {
            ll ans = s[rt + 1] - s[lt]; // Note the use of rt+1 since s is 1-based index for prefix sums
            cout << ans << endl;
        } else {
            cout << 0 << endl; // No elements in the range [l, r]
        }
    }
    return 0;
}