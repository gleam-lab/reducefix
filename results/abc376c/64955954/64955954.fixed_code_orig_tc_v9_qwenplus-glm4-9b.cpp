#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> B[i];
    }

    // Sort the toy sizes and the existing box sizes
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Binary search for the minimum box size x
    int low = 1, high = 1e9 + 1;
    while (low < high) {
        int mid = (low + high) / 2;
        bool isValid = true;

        // Check if it's possible to place all toys in boxes of size A_i and a new box of size mid
        for (int i = 0; i < n; i++) {
            if (A[i] > mid) {
                if (i > 0 && A[i] < B[i - 1]) {
                    isValid = false;
                    break;
                }
                mid = max(mid, A[i]);
            }
        }

        // Adjust binary search bounds
        if (isValid) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    // Output the result
    if (low <= 1e9) {
        cout << low << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}