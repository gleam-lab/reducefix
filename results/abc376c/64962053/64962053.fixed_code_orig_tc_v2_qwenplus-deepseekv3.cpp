#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int i = 0, j = 0;
    int count = 0;
    while (i < n && j < n - 1) {
        if (A[i] <= B[j]) {
            i++;
            j++;
            count++;
        } else {
            j++;
        }
    }
    if (count == n - 1) {
        cout << A.back() << endl;
    } else if (count == n) {
        cout << A.back() << endl;
    } else {
        if (i < n && (count == 0 || A[i] > B.back())) {
            cout << A[i] << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}