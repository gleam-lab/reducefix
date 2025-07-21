#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> x(n), p(n), s(n + 1);

    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        s[i + 1] = s[i] + p[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l; // Convert 1-based index to 0-based index
        --r; // Convert 1-based index to 0-based index

        long long ans = s[r + 1] - s[l];
        cout << ans << '\n';
    }

    return 0;
}