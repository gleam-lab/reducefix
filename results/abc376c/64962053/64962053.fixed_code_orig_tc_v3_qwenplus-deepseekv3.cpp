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
    int count = 0;
    int last_unplaced = -1;

    while (i < n && j < n - 1) {
        if (A[i] <= B[j]) {
            i++;
            j++;
        } else {
            last_unplaced = A[i];
            i++;
        }
    }

    if (i < n) {
        last_unplaced = A[i];
    }

    if (j == n - 1 && i == n - 1) {
        cout << A.back() << endl;
    } else if (j < n - 1 || last_unplaced == -1) {
        cout << -1 << endl;
    } else {
        cout << last_unplaced << endl;
    }

    return 0;
}