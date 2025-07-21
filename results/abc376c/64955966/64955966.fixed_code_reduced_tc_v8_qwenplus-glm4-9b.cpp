#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);

    // Read toy sizes and box sizes
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }

    // Sort toy and box sizes in descending order
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    // Start with the smallest box size that can potentially fit the largest toy
    int x = 0;

    // Try to fit the largest toy into existing boxes
    for (int i = 0; i < N - 1; ++i) {
        if (A[0] <= B[i]) {
            // If the largest toy fits in the current box, no need for an additional box
            cout << 0 << endl;
            return 0;
        }
        if (A[0] > B[i]) {
            // If the current box cannot fit the largest toy, increment box size
            ++x;
        }
    }

    // Check if the largest toy fits in the last box (if x is still 0, it means it fits)
    if (x == 0) {
        cout << 0 << endl;
    } else {
        // If we have incremented x, print the incremented value
        cout << x << endl;
    }

    return 0;
}