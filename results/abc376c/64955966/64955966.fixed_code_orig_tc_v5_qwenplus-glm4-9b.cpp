#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; i++) {
        cin >> B[i];
    }

    // Sort the toy sizes in descending order
    sort(A.begin(), A.end(), greater<int>());
    // Sort the box sizes in descending order
    sort(B.begin(), B.end(), greater<int>());

    // We need the size of the minimum box that can accommodate the largest toy
    // If all toys can fit into the existing boxes, we need the size of the smallest box
    int minBoxSize = N; // Start with a large value

    // Check if all toys fit into the existing boxes
    bool canFit = true;
    for (int i = 0; i < N; i++) {
        if (A[i] > B[i]) {
            canFit = false;
            break;
        }
    }

    if (canFit) {
        // If all toys fit, the smallest box size we need is the size of the smallest box
        minBoxSize = B[0];
    } else {
        // If all toys do not fit into the existing boxes, we need to find the smallest box that can accommodate the largest toy
        int largestToy = A[0];
        for (int boxSize : B) {
            if (boxSize >= largestToy) {
                minBoxSize = boxSize;
                break;
            }
        }
    }

    // If the smallest box size is still set to N, it means we cannot accommodate the largest toy
    if (minBoxSize == N) {
        cout << -1 << endl;
    } else {
        cout << minBoxSize << endl;
    }

    return 0;
}