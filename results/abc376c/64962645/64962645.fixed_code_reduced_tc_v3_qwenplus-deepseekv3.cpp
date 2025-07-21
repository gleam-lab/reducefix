#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n - 1);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n - 1; ++i) cin >> B[i];
    
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    
    int mismatch = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (A[i] > B[i]) {
            mismatch = i;
            break;
        }
    }
    
    if (mismatch == -1) {
        // All toys can fit into existing boxes except possibly the last one
        cout << A.back() << endl;
        return 0;
    }
    
    // The new box must be at least A[mismatch], and we need to check if others can fit
    int x = A[mismatch];
    vector<int> merged;
    merged.reserve(n);
    merged.push_back(x);
    for (int b : B) merged.push_back(b);
    sort(merged.rbegin(), merged.rend());
    
    bool possible = true;
    for (int i = 0; i < n; ++i) {
        if (A[i] > merged[i]) {
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