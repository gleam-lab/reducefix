#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (int qi = 0; qi < q; ++qi) {
        int x, k;
        cin >> x >> k;

        // Find the position of x in sorted array
        auto it = lower_bound(a.begin(), a.end(), x);
        int idx = it - a.begin();

        // Calculate the difference with the k-th closest point
        int diff = abs(a[min(idx + k - 1, n - 1)] - x);
        cout << diff << '\n';
    }

    return 0;
}