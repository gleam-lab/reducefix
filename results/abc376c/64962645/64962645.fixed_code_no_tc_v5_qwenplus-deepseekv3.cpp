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
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    int idx = -1;
    for (int i = 0; i < n; ++i) {
        if (i < n - 1 && A[i] > B[i]) {
            idx = i;
            break;
        }
        if (i == n - 1) {
            idx = i;
            break;
        }
    }
    
    if (idx == -1) {
        cout << 1 << endl;
        return 0;
    }
    
    int x = A[idx];
    int b_ptr = 0;
    bool possible = true;
    
    for (int i = 0; i < n; ++i) {
        if (i == idx) continue;
        if (b_ptr < n - 1 && A[i] <= B[b_ptr]) {
            b_ptr++;
        } else if (A[i] <= x) {
            x = -1; // Mark x as used
        } else {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << A[idx] << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}