#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A, B;

int main() {
    cin >> N;
    A.resize(N);
    B.resize(N-1);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Check if we can fit all toys without any additional box
    bool canFit = true;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > B[i]) {
            canFit = false;
            break;
        }
    }

    if (canFit) {
        cout << "1" << endl; // No need for any additional box
        return 0;
    }

    // Find the minimum box size needed
    int minBoxSize = 0;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > B[i]) {
            minBoxSize = max(minBoxSize, A[i]);
            break;
        }
    }

    if (minBoxSize == 0) {
        minBoxSize = *max_element(A.begin(), A.end()); // If no toy is too big for current boxes
    }

    cout << minBoxSize << endl;

    return 0;
}