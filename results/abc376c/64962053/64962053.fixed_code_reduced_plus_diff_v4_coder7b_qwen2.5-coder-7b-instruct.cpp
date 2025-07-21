#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n);
    vector<int> vb(n - 1);

    for (int i = 0; i < n; i++) {
        cin >> va[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> vb[i];
    }

    // Sort the toy sizes
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    // Calculate the total size of existing boxes
    long long totalBoxSize = accumulate(vb.begin(), vb.end(), 0LL);

    // Check if the largest toy can fit in any of the existing boxes
    if (va[n - 1] <= totalBoxSize) {
        cout << "-1" << endl;
    } else {
        cout << va[n - 1] << endl;
    }

    return 0;
}