#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> va(n), vb(n);
    for (int i = 0; i < n; i++) 
        cin >> va[i];
    for (int i = 0; i < n - 1; i++) 
        cin >> vb[i];

    // Sort both arrays in descending order
    sort(va.begin(), va.end(), greater<long long>());
    sort(vb.begin(), vb.end(), greater<long long>());

    // Find the smallest x such that all toys fit into the boxes
    for (int i = 0; i < n - 1; ++i) {
        if (va[i] > vb[i]) {
            cout << va[i] << endl;
            return 0;
        }
    }

    // If all toys fit into the first N-1 boxes, check if the largest toy fits into the last box
    if (va[n - 1] <= vb[n - 2]) {
        cout << va[n - 1] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}