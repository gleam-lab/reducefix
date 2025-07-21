#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n - 1);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n - 1; i++) cin >> B[i];
    
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    
    int mismatch_pos = -1;
    for (int i = 0; i < n - 1; i++) {
        if (A[i] > B[i]) {
            mismatch_pos = i;
            break;
        }
    }
    
    if (mismatch_pos == -1) {
        // All toys fit into existing boxes except possibly the smallest one
        cout << A.back() << endl;
        return 0;
    }
    
    // The new box must be at least as large as A[mismatch_pos]
    int x = A[mismatch_pos];
    
    // Now check if the remaining toys can fit into the remaining boxes
    // We have to place the new box in the correct position in the B array
    vector<int> new_B = B;
    new_B.insert(new_B.begin() + mismatch_pos, x);
    
    sort(new_B.rbegin(), new_B.rend());
    
    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (A[i] > new_B[i]) {
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