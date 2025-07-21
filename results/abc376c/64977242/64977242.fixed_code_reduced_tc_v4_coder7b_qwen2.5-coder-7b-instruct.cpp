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

    // Sort both arrays in ascending order
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Check if we can fit all toys into existing boxes
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > B[i]) {
            // If not, find the smallest box that can accommodate the largest toy
            int requiredSize = A.back();
            cout << requiredSize << endl;
            return 0;
        }
    }

    // If all toys fit into existing boxes, the largest toy determines the minimum box size needed
    cout << A.back() << endl;

    return 0;
}