#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }

    // Find the maximum toy size
    int maxToySize = *max_element(A.begin(), A.end());

    // Check if there's a box of exactly this size
    bool found = false;
    for (int i = 0; i < N - 1; ++i) {
        if (B[i] == maxToySize) {
            cout << B[i] << endl;
            found = true;
            break;
        }
    }

    // If no such box exists, the answer is the maximum toy size
    if (!found) {
        cout << maxToySize << endl;
    }

    return 0;
}