#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N-1);

    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < N - 1; ++i) cin >> B[i];

    // Sort the sizes of toys and boxes
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Find the maximum toy size that fits into any box
    int maxToySize = 0;
    for(int i = 0; i < N - 1; ++i) {
        if(A[i] <= B[i]) {
            continue;
        } else {
            maxToySize = max(maxToySize, A[i]);
            break;
        }
    }

    // If no toy fits into any box, we need a box larger than the largest toy
    if(maxToySize == 0) {
        maxToySize = A[N-1];
    }

    cout << maxToySize << endl;

    return 0;
}