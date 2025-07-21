#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n - 1);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());  // Sort B in descending order

    int maxToySize = A[n - 1];
    int maxBoxSize = B[0];

    // Find the maximum size in A that is less than or equal to maxBoxSize
    int count = 0;
    for (int i = n - 1; i >= 0 && A[i] <= maxBoxSize; --i) {
        count++;
    }

    // If more than one toy is less than or equal to maxBoxSize, we need an extra box
    // of size maxToySize + 1.
    if (count > 1) {
        cout << maxToySize + 1 << endl;
    } else {
        // If no toy is less than or equal to maxBoxSize, we need to take the next
        // available size which is maxToySize + 1.
        cout << maxToySize + 1 << endl;
    }

    return 0;
}