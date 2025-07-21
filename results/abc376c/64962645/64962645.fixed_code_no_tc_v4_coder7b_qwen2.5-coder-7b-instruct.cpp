#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n - 1);
    for (int i = 0; i < n; ++i)
        cin >> va[i];
    for (int i = 0; i < n - 1; ++i)
        cin >> vb[i];

    sort(va.begin(), va.end(), greater<int>());
    sort(vb.begin(), vb.end(), greater<int>());

    int minBoxSize = INT_MAX;
    bool found = false;
    for (int i = 0; i < n - 1; ++i) {
        if (va[i] <= vb[i]) {
            minBoxSize = min(minBoxSize, vb[i]);
            found = true;
        } else {
            break;
        }
    }

    if (!found) {
        minBoxSize = min(minBoxSize, va.back());
    }

    if (minBoxSize == INT_MAX)
        cout << "-1" << endl;
    else
        cout << minBoxSize << endl;

    return 0;
}