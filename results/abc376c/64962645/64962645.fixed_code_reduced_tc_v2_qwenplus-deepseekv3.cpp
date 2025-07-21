#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n - 1);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n - 1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    int pos = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (A[i] > B[i]) {
            pos = i;
            break;
        }
    }
    
    if (pos == -1) {
        // All toys fit except the smallest one, which can go into the new box
        cout << A.back() << endl;
        return 0;
    }
    
    // The new box must be at least A[pos]
    int x = A[pos];
    // Now, check if the remaining toys can fit into the remaining boxes and the new box
    // We need to ensure that all toys A[i] for i > pos can be placed in B[j] where j >= pos, or in x
    // Also, no two toys can share boxes, and x is already used for A[pos]
    
    // So, the remaining toys are A[pos+1..n-1], boxes are B[pos..n-2], and x is used for A[pos]
    vector<int> remaining_toys(A.begin() + pos + 1, A.end());
    vector<int> remaining_boxes(B.begin() + pos, B.end());
    
    // Check if all remaining_toys can fit into remaining_boxes or x (but x is already used)
    // So, we need to check if each remaining toy is <= some box in remaining_boxes, with each box used at most once
    
    sort(remaining_toys.begin(), remaining_toys.end(), greater<int>());
    sort(remaining_boxes.begin(), remaining_boxes.end(), greater<int>());
    
    bool possible = true;
    for (int i = 0; i < remaining_toys.size(); ++i) {
        if (i < remaining_boxes.size()) {
            if (remaining_toys[i] > remaining_boxes[i]) {
                possible = false;
                break;
            }
        } else {
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