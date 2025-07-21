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
    int unmatched = -1;
    
    while (i < n && j < n - 1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
        } else {
            unmatched = A[i];
            ++i;
        }
    }
    
    if (i < n) {
        unmatched = A.back();
    }
    
    if (unmatched == -1) {
        cout << 1 << endl; // All toys matched, x can be any >=1, so min is 1
    } else {
        bool possible = true;
        for (int k = 0; k < n - 1; ++k) {
            if (B[k] < A[k]) {
                possible = false;
                break;
            }
        }
        if (possible) {
            cout << unmatched << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}