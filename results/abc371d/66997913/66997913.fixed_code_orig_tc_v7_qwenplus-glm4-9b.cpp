#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), s(n + 1);
    vector<ll> p(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        cin >> p[i];
        s[i + 1] = s[i] + p[i];
    }
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        int rt = upper_bound(x.begin(), x.end(), r) - x.begin();
        int lt = lower_bound(x.begin(), x.end(), l) - x.begin();
        // Adjust for the fact that upper_bound and lower_bound return one-based indices
        ll ans = s[rt] - s[lt];
        cout << ans << endl;
    }
    return 0;
}