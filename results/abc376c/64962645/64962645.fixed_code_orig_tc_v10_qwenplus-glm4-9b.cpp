#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    vector<int> B(n - 1);
    vector<int> B_sorted(n - 1);

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        cin >> B[i];
    }
    
    // Copy B to B_sorted and sort it
    copy(B.begin(), B.end(), B_sorted.begin());
    sort(B_sorted.begin(), B_sorted.end());

    // Initialize the answer to a large number
    int ans = INT_MAX;

    // Check the minimum box size needed
    for (int i = 0; i < n - 1; ++i) {
        if (A[i] <= B_sorted[i]) {
            // If the current toy can fit in the sorted box, update the answer to the box size
            ans = min(ans, B_sorted[i]);
        } else {
            // If the current toy cannot fit, the next box is too large for this toy
            break;
        }
    }

    // If all toys have been placed, check if there's any space for the last toy
    if (ans == INT_MAX && A[n-1] <= B_sorted[n-2]) {
        ans = B_sorted[n-2];
    }

    // If the answer is still INT_MAX, it means it's not possible to store all toys
    if (ans == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}