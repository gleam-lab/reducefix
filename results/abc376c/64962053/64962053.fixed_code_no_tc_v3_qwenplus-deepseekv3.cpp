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
    
    int i = n - 1, j = n - 2;
    int needed_x = -1;
    while (i >= 0 && j >= 0) {
        if (A[i] <= B[j]) {
            --i;
            --j;
        } else {
            if (needed_x == -1) {
                needed_x = A[i];
                --i;
            } else {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    if (i >= 0) {
        if (needed_x == -1) {
            needed_x = A[i];
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << needed_x << endl;
    return 0;
}