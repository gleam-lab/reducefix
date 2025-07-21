#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);

    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    // Create a vector of all box sizes, including the potential new box size
    vector<long long> boxes(N + 1, 0);
    for (int i = 0; i < N; i++) {
        boxes[i] = A[i];  // Add toy sizes
    }
    for (int i = 0; i < N - 1; i++) {
        boxes[i + 1] = B[i];  // Add existing box sizes
    }

    // Sort the sizes to be able to check the feasibility of storing toys
    sort(boxes.begin(), boxes.end());

    // Check if all toys can be stored in existing boxes
    for (int i = 0; i < N; i++) {
        // If a toy cannot fit into any box
        if (boxes[i] < A[i]) {
            // Check if there is a larger box that can fit all toys
            auto it = upper_bound(boxes.begin(), boxes.end(), A[i]);
            if (it == boxes.end()) {
                cout << -1 << endl;
                return 0;
            } else {
                // Print the size of the smallest box that can fit all toys
                cout << *it << endl;
                return 0;
            }
        }
    }

    // If all toys can already fit into existing boxes, no additional box is needed
    cout << -1 << endl;
    return 0;
}