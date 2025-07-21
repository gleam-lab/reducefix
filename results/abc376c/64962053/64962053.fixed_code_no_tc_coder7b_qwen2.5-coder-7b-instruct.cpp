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
        if (A[i] > B[i]) {
            x = max(x, A[i]);
        }
    }

    if (x == -1) {
        cout << A[n-1] << endl;
    } else {
        for (int i = 0; i < n-1; ++i) {
            if (A[i] <= B[i] && A[i+1] > B[i]) {
                x = max(x, A[i+1]);
                break;
            }
        }
        cout << x << endl;
    }
}