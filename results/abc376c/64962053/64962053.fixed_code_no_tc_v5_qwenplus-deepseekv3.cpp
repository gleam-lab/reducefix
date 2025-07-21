#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n - 1);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n - 1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int i = 0, j = 0;
    int count = 0;
    int required_x = -1;
    
    while (i < n && j < n - 1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
        } else {
            required_x = A[i];
            ++i;
        }
    }
    
    if (i < n) {
        required_x = A.back();
    }
    
    if (required_x == -1) {
        // All toys fit in existing boxes, so x can be any positive integer, but the smallest is 1
        cout << 1 << endl;
    } else {
        bool possible = true;
        // Check if all toys except one can fit in existing boxes
        // The new box x must be >= required_x
        // Also, we need to ensure that the remaining toys can fit in the remaining boxes
        // which is already handled by the while loop
        cout << required_x << endl;
    }
    
    return 0;
}