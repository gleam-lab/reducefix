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
    
    int i = 0, j = 0;
    int unmatched = 0;
    int x = -1;
    
    while (i < n && j < n - 1) {
        if (A[i] <= B[j]) {
            i++;
            j++;
        } else {
            unmatched++;
            if (unmatched > 1) {
                cout << -1 << endl;
                return 0;
            }
            x = A[i];
            i++;
        }
    }
    
    if (i < n) {
        unmatched += (n - i);
        if (unmatched > 1) {
            cout << -1 << endl;
            return 0;
        }
        x = A.back();
    }
    
    if (unmatched == 0) {
        x = 1; // All toys fit in existing boxes; any x >= 1 works, but smallest is 1
    }
    
    cout << x << endl;
    
    return 0;
}