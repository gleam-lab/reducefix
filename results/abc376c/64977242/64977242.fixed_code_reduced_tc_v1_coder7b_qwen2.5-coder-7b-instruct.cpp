#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N-1);

    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    // Sort both arrays to facilitate finding the minimum box size
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Check if we can place all toys in the existing boxes
    bool canPlace = true;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > B[i]) {
            canPlace = false;
            break;
        }
    }

    if (canPlace) {
        cout << "0" << endl; // No need to buy any new box
        return 0;
    }

    // Find the minimum box size needed to accommodate the largest toy
    int minBoxSize = A[N-1]; // The largest toy will determine the minimum required box size

    cout << minBoxSize << endl;

    return 0;
}