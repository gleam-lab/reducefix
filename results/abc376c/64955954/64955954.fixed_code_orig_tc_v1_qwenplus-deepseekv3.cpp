#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n - 1);

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int mismatch_pos = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (A[i + 1] > B[i]) {
            mismatch_pos = i;
            break;
        }
    }

    if (mismatch_pos == -1) {
        // All toys except possibly A[0] can be placed in B's boxes.
        // The new box must be at least A[0].
        cout << A[0] << endl;
    } else {
        // Check if the only issue is at mismatch_pos.
        bool possible = true;
        for (int i = mismatch_pos + 1; i < n - 1; ++i) {
            if (A[i + 1] > B[i]) {
                possible = false;
                break;
            }
        }
        if (possible) {
            // The new box must be at least A[mismatch_pos + 1], provided A[mismatch_pos] <= B[mismatch_pos]
            // But wait, we need to ensure that A[mismatch_pos] can be placed in some box.
            // So, after placing A[mismatch_pos + 1] in the new box, we need to check if A[mismatch_pos] <= B[mismatch_pos - 1] (if mismatch_pos > 0)
            if (mismatch_pos == 0 || A[mismatch_pos] <= B[mismatch_pos - 1]) {
                cout << A[mismatch_pos + 1] << endl;
            } else {
                cout << -1 << endl;
            }
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}