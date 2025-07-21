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
    
    int needed_x = -1;
    bool possible = true;
    
    for (int i = n - 1, j = n - 2; i >= 0; --i, --j) {
        if (i == 0) {
            // The smallest toy must fit into x
            needed_x = A[i];
        } else {
            if (j >= 0) {
                if (A[i] > B[j]) {
                    if (needed_x == -1) {
                        needed_x = A[i];
                    } else {
                        possible = false;
                        break;
                    }
                }
            } else {
                if (A[i] > needed_x) {
                    possible = false;
                    break;
                }
            }
        }
    }
    
    if (possible) {
        cout << needed_x << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}