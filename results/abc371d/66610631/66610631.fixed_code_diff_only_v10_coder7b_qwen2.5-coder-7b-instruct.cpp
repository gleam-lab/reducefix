#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 1e6+7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        c[i] = c[i - 1] + b[i];
    }

    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        auto l_i = lower_bound(a.begin() + 1, a.end(), l);
        auto r_i = upper_bound(a.begin() + 1, a.end(), r);

        // Adjusting indices to be zero-based for simplicity
        int left_index = distance(a.begin() + 1, l_i);
        int right_index = distance(a.begin() + 1, r_i);

        if (left_index == 0 && right_index == n) {
            cout << c[n] << endl;
        } else if (right_index == n) {
            cout << c[n] - c[left_index] << endl;
        } else if (left_index == 0) {
            cout << c[right_index] << endl;
        } else {
            cout << c[right_index] - c[left_index] << endl;
        }
    }

    return 0;
}