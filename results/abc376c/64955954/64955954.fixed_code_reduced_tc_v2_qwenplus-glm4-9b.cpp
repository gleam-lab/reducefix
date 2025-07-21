#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n-1);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n-1; i++) {
        cin >> B[i];
    }

    sort(A.begin(), A.end(), greater<int>());  // Sort A in descending order
    sort(B.begin(), B.end(), greater<int>());  // Sort B in descending order

    int x = -1;  // Start with -1 assuming it's not possible
    bool possible = false;

    // Try to find the smallest box size x that can fit a toy
    for (int i = 0; i < n; i++) {
        if (A[i] <= B[i] || (i < n - 1 && A[i] <= B[i+1])) {
            x = A[i];
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << x << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}