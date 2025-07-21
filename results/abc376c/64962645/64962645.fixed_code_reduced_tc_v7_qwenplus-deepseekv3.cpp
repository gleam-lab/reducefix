#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n - 1);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n - 1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    // We need to find the smallest x such that:
    // The largest N-1 toys can be matched to the N-1 boxes (B), each A_i <= B_j
    // The remaining toy must be <= x.
    
    // The approach is to check if the N-1 largest toys can be matched to the N-1 boxes.
    // If not, then it's impossible; otherwise, x is the remaining toy's size.
    
    // So, sort both in ascending order, then check for each i from 0 to N-2 if A[i+1] <= B[i].
    // The remaining toy is A[0], so x must be >= A[0].
    
    bool possible = true;
    for (int i = 0; i < n - 1; ++i) {
        if (A[i + 1] > B[i]) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << A[0] << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}