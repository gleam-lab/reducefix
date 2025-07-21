#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n - 1);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n - 1; i++) cin >> B[i];
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int x = -1;
    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            if (A[i] > B[i]) {
                // The toy at i cannot be placed in any of the existing boxes
                // So, the new box must be at least A[i]
                // Additionally, we need to check if the remaining toys can fit in the remaining boxes
                // The problem reduces to whether the largest N-1 toys can fit into the largest N-1 boxes
                // If not, then it's impossible
                bool possible = true;
                for (int j = i; j < n - 1; j++) {
                    if (A[j + 1] > B[j]) {
                        possible = false;
                        break;
                    }
                }
                if (possible) {
                    x = A[i];
                } else {
                    x = -1;
                }
                break;
            }
        } else {
            // The last toy must be placed in the new box
            x = A[i];
        }
    }
    
    cout << x << endl;
    return 0;
}