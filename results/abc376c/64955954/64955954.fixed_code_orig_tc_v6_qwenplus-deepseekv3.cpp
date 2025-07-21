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
    
    int pos = -1;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > B[i]) {
            pos = i;
            break;
        }
    }
    
    if (pos == -1) {
        // All toys up to N-1 fit into the first N-1 boxes. The last toy needs to fit into x.
        cout << (A.back() <= B.back() ? B.back() : A.back()) << endl;
    } else {
        // Check if the problematic toy can fit into any of the remaining boxes or if x can cover it
        bool possible = true;
        for (int i = pos + 1; i < N - 1; ++i) {
            if (A[i] > B[i - 1]) {
                possible = false;
                break;
            }
        }
        if (!possible) {
            cout << -1 << endl;
        } else {
            // The toy at pos needs to fit into x, and x must be at least A[pos]
            // Also, the last toy must fit into x if it's larger than B.back()
            int x_min = A[pos];
            if (N > 1 && A.back() > B.back()) {
                x_min = max(x_min, A.back());
            }
            cout << x_min << endl;
        }
    }
    
    return 0;
}