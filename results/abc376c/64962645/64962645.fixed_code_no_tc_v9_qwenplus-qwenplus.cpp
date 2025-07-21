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

    // Sort toys and boxes in descending order
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    // Try to fit the largest toy in each box or the new box
    int extra_box_needed_for = -1;

    // Two pointers approach
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (j < n - 1 && A[i] <= B[j]) {
            j++; // this toy fits in one of the existing boxes
        } else {
            // This toy must go into the new box
            extra_box_needed_for = i;
        }
    }

    if (extra_box_needed_for == -1) {
        // All toys fit in the given boxes, we can use size 0 as extra
        cout << 0 << endl;
    } else {
        cout << A[extra_box_needed_for] << endl;
    }

    return 0;
}