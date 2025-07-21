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
    
    int min_x = -1;
    bool possible = true;
    
    for (int i = 0; i < n - 1; ++i) {
        if (B[i] < A[i + 1]) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        min_x = A[0];
    } else {
        possible = true;
        for (int i = 0; i < n - 1; ++i) {
            if (B[i] < A[i]) {
                possible = false;
                break;
            }
        }
        if (possible) {
            min_x = A[n - 1];
        } else {
            min_x = -1;
        }
    }
    
    cout << min_x << endl;
    return 0;
}