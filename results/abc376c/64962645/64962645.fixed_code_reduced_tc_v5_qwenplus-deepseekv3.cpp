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
    
    int required_x = -1;
    int mismatch_pos = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (A[i] > B[i]) {
            mismatch_pos = i;
            break;
        }
    }
    
    if (mismatch_pos == -1) {
        // All toys can be placed in the existing boxes, then the new box can be as small as the smallest toy.
        required_x = A.back();
    } else {
        // Check if the mismatch is only at one position, and if the new box can accommodate A[mismatch_pos]
        // and the remaining toys can fit into the remaining boxes (including the new one).
        // The new box must be >= A[mismatch_pos], and the remaining toys (A[mismatch_pos + 1 ... n-1]) must fit into B[mismatch_pos ... n-2]
        bool possible = true;
        for (int i = mismatch_pos + 1; i < n - 1; ++i) {
            if (A[i] > B[i - 1]) {
                possible = false;
                break;
            }
        }
        if (possible && (n == 2 || A.back() <= B.back())) {
            required_x = A[mismatch_pos];
        } else {
            possible = false;
        }
        
        if (!possible) {
            // Another check: sometimes the mismatch is not the only one, but adding the new box can help if we shift placements.
            // Alternatively, it might be impossible.
            required_x = -1;
        }
    }
    
    // Additional check: if after placing the largest toys, the smallest toy is larger than the smallest box.
    if (required_x != -1) {
        // Verify that all toys can be placed in boxes (existing + new box of size required_x)
        vector<int> boxes = B;
        boxes.push_back(required_x);
        sort(boxes.begin(), boxes.end(), greater<int>());
        sort(A.begin(), A.end(), greater<int>());
        bool valid = true;
        for (int i = 0; i < n; ++i) {
            if (A[i] > boxes[i]) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            required_x = -1;
        }
    }
    
    cout << required_x << endl;
    
    return 0;
}