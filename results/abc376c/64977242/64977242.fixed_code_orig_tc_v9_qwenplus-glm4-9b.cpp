#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N-1);

    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N-1; i++) cin >> B[i];

    // Sort the toy sizes and box sizes
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int canStoreInExistingBoxes = true;
    for (int i = 0; i < N; i++) {
        if (A[i] > B[i]) {
            canStoreInExistingBoxes = false;
            break;
        }
    }

    // If it's possible to store all toys in the existing boxes, output the size of the largest box
    if (canStoreInExistingBoxes) {
        cout << B.back() << endl; // The largest box size is at the end of the sorted B vector
        return 0;
    }

    // If not, find the minimum box size needed
    // The minimum box size needed would be the size of the largest toy that cannot be stored in an existing box
    int minBoxSize = A[0]; // Start with the largest toy that is not stored in an existing box

    // Iterate over the toy sizes and find the minimum box size needed
    for (int i = 0; i < N; i++) {
        if (A[i] > B[i]) {
            minBoxSize = max(minBoxSize, A[i]);
        }
    }

    // Output the minimum box size
    cout << minBoxSize << endl;

    return 0;
}