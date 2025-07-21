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
    int missing = -1;
    while (i < n && j < n - 1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
        } else {
            if (missing != -1) {
                cout << -1 << endl;
                return 0;
            }
            missing = A[i];
            ++i;
        }
    }
    if (i < n) {
        if (missing != -1) {
            cout << -1 << endl;
            return 0;
        }
        missing = A.back();
    }
    if (missing == -1) {
        cout << A.back() << endl;
    } else {
        cout << missing << endl;
    }
    return 0;
}