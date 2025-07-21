#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> x(n + 1), p(n + 1), a(n + 1);

    // Read the positions and population of each village
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= n; ++i) cin >> p[i];

    // Calculate the prefix sum array
    for (int i = 1; i <= n; ++i) a[i] = a[i - 1] + p[i];

    int q;
    cin >> q;
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        // Find the first index whose position is greater than or equal to l
        auto it1 = lower_bound(x.begin(), x.end(), l);
        int idx1 = it1 - x.begin();
        
        // Find the first index whose position is greater than r
        auto it2 = upper_bound(x.begin(), x.end(), r);
        int idx2 = it2 - x.begin();
        
        // If no village is found within the range [l, r], print 0
        if (idx1 > idx2) cout << "0\n";
        else cout << a[idx2] - a[idx1 - 1] << "\n";
    }

    return 0;
}