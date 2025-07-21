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
        // Find the positions of l and r in the sorted order of x
        auto it_l = lower_bound(x.begin(), x.end(), l);
        auto it_r = upper_bound(x.begin(), x.end(), r);
        int left_idx = it_l - x.begin();
        int right_idx = it_r - x.begin();
        
        // Since upper_bound gives the position just after the last element equal to r,
        // if right_idx is not at the end of the vector, we need to decrement it to get the correct prefix sum index.
        if (right_idx < n && x[right_idx - 1] == r) {
            right_idx--;
        }
        
        // Calculate the sum of p values for indices corresponding to the range [l, r] in the sorted order of x
        ll ans = s[right_idx + 1] - s[left_idx];
        cout << ans << endl;
    }
    return 0;
}