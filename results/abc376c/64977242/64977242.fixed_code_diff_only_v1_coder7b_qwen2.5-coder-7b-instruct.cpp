#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N-1);

    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    // Sort both arrays to facilitate finding the minimum box size needed
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Iterate through each pair of toy and box sizes
    for (int i = 0; i < N - 1; i++) {
        // If a toy cannot fit into any available box, return -1
        if (A[i] > B[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    // The largest toy size determines the minimum box size needed
    int minBoxSize = A.back();

    cout << minBoxSize << endl;

    return 0;
}