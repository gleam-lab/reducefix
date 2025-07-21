#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<long long> A, B;

int main() {
    cin >> N;
    A.resize(N);
    B.resize(N-1);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Check if we can fit all toys into the existing boxes without needing a new one
    bool canStoreWithExistingBoxes = true;
    for (int i = 0; i < N - 1; i++) {
        if (A[i] > B[i]) {
            canStoreWithExistingBoxes = false;
            break;
        }
    }

    if (canStoreWithExistingBoxes) {
        cout << "0" << endl; // No need to buy a new box
        return 0;
    }

    // If we need a new box, find the smallest size required
    long long maxBoxSize = *max_element(B.begin(), B.end());
    long long minRequiredSize = *max_element(A.begin(), A.end()) + 1;

    if (minRequiredSize <= maxBoxSize) {
        cout << "0" << endl; // The largest available box is sufficient
    } else {
        cout << minRequiredSize - maxBoxSize << endl; // The difference needed
    }

    return 0;
}