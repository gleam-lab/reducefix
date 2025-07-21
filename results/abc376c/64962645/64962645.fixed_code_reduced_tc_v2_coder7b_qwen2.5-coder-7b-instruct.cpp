#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n);
    for (int i = 0; i < n; ++i) cin >> va[i];
    for (int i = 0; i < n - 1; ++i) cin >> vb[i];

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    long long minBoxSize = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (va[i] > vb[i]) {
            minBoxSize = max(minBoxSize, 1LL * (va[i] + vb[i]));
        }
    }

    if (minBoxSize == 0) {
        cout << -1 << endl;
    } else {
        cout << minBoxSize << endl;
    }

    return 0;
}