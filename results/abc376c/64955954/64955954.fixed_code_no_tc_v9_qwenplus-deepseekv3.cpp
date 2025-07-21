#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n - 1);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n - 1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    vector<int> unmatched;
    int i = 0, j = 0;
    while (i < n && j < n - 1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
        } else {
            ++j;
        }
    }
    
    if (i == n) {
        // All toys matched, but we have to buy an extra box (min x can be anything >=0)
        cout << 1 << endl;
    } else if (i == n - 1) {
        // Exactly one toy unmatched, the new box must be >= A[i]
        cout << A[i] << endl;
    } else {
        // More than one toy unmatched, impossible
        cout << -1 << endl;
    }
    
    return 0;
}