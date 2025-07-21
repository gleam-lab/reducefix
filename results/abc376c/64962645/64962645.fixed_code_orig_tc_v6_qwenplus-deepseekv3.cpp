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
    
    int pos = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (A[i] > B[i]) {
            pos = i;
            break;
        }
    }
    
    if (pos == -1) {
        cout << A.back() << endl;
        return 0;
    }
    
    int x_candidate = A[pos];
    
    vector<int> new_B = B;
    new_B.insert(new_B.begin() + pos, x_candidate);
    
    bool possible = true;
    for (int i = 0; i < n; ++i) {
        if (A[i] > new_B[i]) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << x_candidate << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}