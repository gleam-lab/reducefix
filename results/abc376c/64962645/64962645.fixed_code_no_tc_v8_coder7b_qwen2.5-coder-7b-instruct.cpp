#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<long long> va(n), vb(n);
    for (int i = 0; i < n; ++i)
        cin >> va[i];
    for (int i = 0; i < n - 1; ++i)
        cin >> vb[i];

    // Sort both arrays in descending order
    sort(va.begin(), va.end(), greater<long long>());
    sort(vb.begin(), vb.end(), greater<long long>());

    // Find the maximum size required to fit all toys
    long long max_needed = *max_element(va.begin(), va.end());

    // Check if we can fit all toys with the current box sizes
    for (int i = 0; i < n - 1; ++i) {
        if (va[i] > vb[i]) {
            max_needed = max(max_needed, va[i]);
            break;
        }
    }

    // If the largest toy is smaller than the largest box, we don't need any new box
    if (max_needed <= vb[n - 2]) {
        cout << "0" << endl;
    } else {
        cout << max_needed << endl;
    }

    return 0;
}