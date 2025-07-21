#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 1e6+7;
int main() {
    int n, m;
    cin >> n;
    vector<int> a(n+1, 0), b(n+1, 0), c(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        c[i] = b[i] + (i > 1 ? c[i-1] : 0);  // Use conditional operator for clarity
    }
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        auto l_i = lower_bound(a.begin() + 1, a.end(), l);
        auto r_j = upper_bound(a.begin() + 1, a.end(), r);
        int i = distance(a.begin() + 1, l_i);  // Correctly calculate the index
        int j = distance(a.begin() + 1, r_j);  // Correctly calculate the index
        if (r == a[n]) {
            cout << c[n] - (i > 0 ? c[i-1] : 0) << endl;  // Use conditional operator for clarity
        } else {
            cout << c[j - 1] - (i > 0 ? c[i - 1] : 0) << endl;  // Use conditional operator for clarity and handle case when i is 0
        }
    }
    return 0;
}