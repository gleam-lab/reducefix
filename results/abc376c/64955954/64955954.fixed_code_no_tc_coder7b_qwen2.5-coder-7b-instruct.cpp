#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n-1);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n-1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int x = -1;
    for (int i = 0; i < n-1; ++i) {
        if (B[i] < A[i]) {
            x = max(x, A[i]);
        }
    }

    if (x == -1) {
        cout << A[0] << endl;
    } else {
        bool found = false;
        for (int i = 0; i < n-1; ++i) {
            if (B[i] >= A[n-1]) {
                found = true;
                break;
            }
        }
        if (found) {
            cout << x << endl;
        } else {
            cout << max(x, A[n-1]) << endl;
        }
    }
}