#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);

    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    // Sort toy sizes in descending order
    sort(A.begin(), A.end(), greater<long long>());

    // If the largest toy can fit into the smallest box, no new box is needed
    if (A[0] <= B[0]) {
        cout << B[0] << endl;
        return 0;
    }

    // Initialize variables to track the maximum toy size that can fit into a box
    long long maxToyInBox = B[0];

    // Iterate over the boxes to find the maximum toy size that can fit into an existing box
    for (int i = 0; i < N - 1; ++i) {
        if (A[i + 1] <= B[i]) {
            continue;
        }
        // Calculate the next possible box size if the current largest toy doesn't fit
        maxToyInBox = A[i + 1] + 1;
    }

    // Special case: if the next largest toy doesn't fit into any existing box
    if (A[N - 1] > maxToyInBox) {
        maxToyInBox = A[N - 1] + 1;
    }

    cout << maxToyInBox << endl;
    return 0;
}