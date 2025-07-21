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
    
    int x = -1;
    int i = 0, j = 0;
    int mismatch = 0;
    
    while (i < n && j < n - 1) {
        if (A[i] <= B[j]) {
            i++;
            j++;
        } else {
            mismatch++;
            if (mismatch > 1) {
                cout << -1 << endl;
                return 0;
            }
            x = A[i];
            i++;
        }
    }
    
    if (i < n) {
        x = A[n - 1];
    }
    
    if (x == -1) {
        x = 1; // all toys can be placed in existing boxes, but we need to buy a box. The minimal x is 1.
    }
    
    // Verify if x is sufficient by checking if all toys can be placed when x is the minimal required
    // Now, simulate the placement with x added to B
    vector<int> newB = B;
    newB.push_back(x);
    sort(newB.begin(), newB.end());
    
    bool possible = true;
    for (int i = 0; i < n; ++i) {
        if (A[i] > newB[i]) {
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