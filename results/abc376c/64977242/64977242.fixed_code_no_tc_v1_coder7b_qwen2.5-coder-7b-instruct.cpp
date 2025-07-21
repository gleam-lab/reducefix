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

    // Sort both arrays in ascending order
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Check if there is any toy that cannot fit into any existing box
    for (int i = 0; i < N - 1; i++) {
        if (A[i] > B[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    // Find the maximum size among all toys and boxes
    long long maxToySize = *max_element(A.begin(), A.end());
    long long maxBoxSize = *max_element(B.begin(), B.end());

    // The minimum size of the new box needed should be at least the size of the largest toy
    long long minNewBoxSize = maxToySize;

    // If the largest toy can fit into the largest box, we don't need a new box
    if (minNewBoxSize <= maxBoxSize) {
        cout << "0" << endl; // No new box needed
    } else {
        cout << minNewBoxSize << endl; // Print the minimum size of the new box needed
    }

    return 0;
}