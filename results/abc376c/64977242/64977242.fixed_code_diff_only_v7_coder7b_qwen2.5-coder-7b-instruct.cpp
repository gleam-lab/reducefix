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

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Find the maximum required box size
    int maxRequiredSize = 0;
    for (int i = 0; i < N - 1; i++) {
        if (A[i] > B[i]) {
            maxRequiredSize = A[i];
            break;
        }
    }

    // If no toy is larger than any box, we need a box as large as the largest toy
    if (maxRequiredSize == 0) {
        maxRequiredSize = A.back();
    }

    cout << maxRequiredSize << endl;

    return 0;
}