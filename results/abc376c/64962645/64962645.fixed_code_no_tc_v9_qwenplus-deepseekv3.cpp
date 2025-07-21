#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n - 1);

    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    int x = -1;
    bool possible = true;
    int mismatch_pos = -1;

    for (int i = 0; i < n; ++i) {
        if (i < n - 1) {
            if (A[i] > B[i]) {
                mismatch_pos = i;
                break;
            }
        } else {
            mismatch_pos = i;
            break;
        }
    }

    if (mismatch_pos == -1) {
        // All toys fit into the existing boxes
        cout << 1 << endl;
        return 0;
    }

    x = A[mismatch_pos];

    // Now, check if the remaining toys can fit into the remaining boxes
    // We have to skip the mismatch box and see if the rest can fit
    vector<int> newB;
    newB.reserve(n - 1);
    newB = B;
    newB.push_back(x);
    sort(newB.begin(), newB.end(), greater<int>());

    possible = true;
    for (int i = 0; i < n; ++i) {
        if (A[i] > newB[i]) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << x << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}