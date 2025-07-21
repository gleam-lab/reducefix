#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    vector<int> possible_x;
    
    // Check if we can place all toys without the new box
    bool possible = true;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > B[i]) {
            possible = false;
            break;
        }
    }
    if (possible) {
        cout << 0 << endl;
        return 0;
    }
    
    // Now, check which x is needed
    // The new box must cover at least one toy that cannot be placed otherwise
    // We need x >= A[k], where k is the smallest index such that A[k] > B[k] (if k exists)
    // But also, the remaining toys must fit into the existing boxes
    
    // The approach is to try inserting x into the B array and see if all toys can fit
    // We need to find the minimal x such that when B is sorted with x, each A[i] <= B[i]
    
    // Alternative approach: find the minimal x such that:
    // There is exactly one A[i] that is larger than B[i-1] (if i > 0) and B[i] (original B)
    // So x must be >= that A[i], and the rest must fit
    
    // Let's try to find the toy that is the problematic one
    
    int required_x = -1;
    
    // We will try to find if there's exactly one position where A[i] is not covered by B's i-th (or i-1th)
    // So the new x must cover exactly that position
    
    // The idea is to find the minimal x such that:
    // For all i < k, A[i] <= B[i]
    // For all i > k, A[i] <= B[i-1]
    // And x >= A[k]
    
    // So k is the position where the new x is placed
    
    for (int k = 0; k < N; ++k) {
        bool ok = true;
        // Check all toys before k: A[i] <= B[i] (since B has one more element)
        for (int i = 0; i < k; ++i) {
            if (i >= B.size()) {
                ok = false;
                break;
            }
            if (A[i] > B[i]) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        // Check all toys after k: A[i] <= B[i-1] (since B is one less)
        for (int i = k + 1; i < N; ++i) {
            if (i - 1 >= B.size()) {
                ok = false;
                break;
            }
            if (A[i] > B[i - 1]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            if (required_x == -1 || A[k] < required_x) {
                required_x = A[k];
            }
        }
    }
    
    if (required_x != -1) {
        cout << required_x << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}