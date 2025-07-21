#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> va(n), vb(n - 1);

    for (int i = 0; i < n; i++) {
        cin >> va[i];
    }

    for (int i = 0; i < n - 1; i++) {
        cin >> vb[i];
    }

    sort(va.begin(), va.end(), greater<int>());
    sort(vb.begin(), vb.end(), greater<int>());

    long long minBoxSize = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (va[i] > vb[i]) {
            minBoxSize = max(minBoxSize, (long long)va[i]);
        }
    }

    cout << (minBoxSize == -1 ? -1 : minBoxSize) << endl;

    return 0;
}