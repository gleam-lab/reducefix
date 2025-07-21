#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> A(n), B(n - 1);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    multiset<long long> boxSizes;
    int j = 0;
    for (int i = 0; i < n - 1; ++i) {
        while (j < n && A[j] <= B[i]) {
            boxSizes.insert(A[j]);
            ++j;
        }
        if (!boxSizes.empty()) {
            boxSizes.erase(boxSizes.begin()); // Assign smallest available toy to this box
        } else {
            cout << -1 << endl;
            return 0;
        }
    }

    // One toy remains unassigned, find the minimal x to fit it
    if (j < n) {
        cout << A[j] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}