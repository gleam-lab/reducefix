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

    // Check if the largest toy can fit in any of the existing boxes
    if (A.back() <= B.back()) {
        cout << A.back() << endl;
        return 0;
    }

    // Find the smallest box that can fit the largest toy
    for (int i = 0; i < N - 1; i++) {
        if (A.back() <= B[i]) {
            cout << B[i] << endl;
            return 0;
        }
    }

    // If no box can fit the largest toy, we need to buy a new box
    cout << A.back() << endl;

    return 0;
}