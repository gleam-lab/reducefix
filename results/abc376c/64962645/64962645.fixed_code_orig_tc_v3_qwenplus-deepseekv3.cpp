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
    
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    
    int unmatched = 0;
    int x = 0;
    int i = 0, j = 0;
    
    while (i < n && j < n - 1) {
        if (A[i] <= B[j]) {
            i++;
            j++;
        } else {
            unmatched++;
            x = A[i];
            i++;
        }
    }
    
    while (i < n) {
        unmatched++;
        x = A[i];
        i++;
    }
    
    if (unmatched > 1) {
        cout << -1 << endl;
    } else {
        cout << x << endl;
    }
    
    return 0;
}