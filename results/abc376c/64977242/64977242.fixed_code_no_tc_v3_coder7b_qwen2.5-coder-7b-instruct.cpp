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

    bool canStore = true;
    for (int i = 0; i < N - 1; i++) {
        if (A[i] > B[i]) {
            canStore = false;
        }
    }

    if (!canStore) {
        cout << -1 << endl;
        return 0;
    }

    // Find the minimum box size that can accommodate the largest toy
    long long minBoxSize = A[N-1]; // The largest toy needs at least this space

    // Check if any existing box can fit the largest toy
    for (int i = 0; i < N - 1; i++) {
        if (minBoxSize <= B[i]) {
            minBoxSize = B[i]; // Use the smallest box that fits the largest toy
            break;
        }
    }

    cout << minBoxSize << endl;

    return 0;
}