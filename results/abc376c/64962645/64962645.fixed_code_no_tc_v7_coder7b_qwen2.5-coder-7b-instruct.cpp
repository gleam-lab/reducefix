#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> va(n), vb(n - 1);
    for (int i = 0; i < n; i++) cin >> va[i];
    for (int i = 0; i < n - 1; i++) cin >> vb[i];

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    long long minSize = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (va[i] > vb[i]) {
            minSize = max(minSize, (long long)va[i]);
        }
    }

    // Check if we need to consider the largest toy
    if (minSize == 0) {
        minSize = va.back();
    }

    cout << minSize << endl;

    return 0;
}