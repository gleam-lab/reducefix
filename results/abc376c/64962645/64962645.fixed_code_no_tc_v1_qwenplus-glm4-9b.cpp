#include <iostream>
#include <vector>
#include <algorithm>
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
    
    // Sort both toy sizes and box sizes in descending order
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    // If the largest toy size is less than the largest box size,
    // we can place all toys without needing a new box
    if (A[0] < B[0]) {
        cout << -1 << endl;
        return 0;
    }

    // Initialize the minimum box size required to the size of the largest toy
    int minBoxSizeRequired = A[0];

    // Check if the current largest box size can fit the current largest toy
    // and if so, check if the next largest toy can fit into the same or a smaller box
    for (int i = 0; i < n - 1; ++i) {
        if (A[i + 1] < B[0]) {
            // If the next largest toy does not fit in the largest box,
            // then we need a new box of size at least as large as the next largest toy
            minBoxSizeRequired = A[i + 1];
            break;
        }
    }

    // Output the minimum box size required
    cout << minBoxSizeRequired << endl;
    return 0;
}