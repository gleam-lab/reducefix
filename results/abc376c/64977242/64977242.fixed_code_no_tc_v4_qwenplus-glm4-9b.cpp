#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }

    // Check if all toys can be stored in the existing boxes
    for (int i = 0; i < N; ++i) {
        bool placed = false;
        for (int j = 0; j < N - 1; ++j) {
            if (A[i] <= B[j]) {
                placed = true;
                break;
            }
        }
        if (!placed) {
            cout << -1 << endl;
            return 0;
        }
    }

    // Sort the toy sizes in descending order to find the minimum required box size
    sort(A.rbegin(), A.rend());

    // The first toy size in the sorted list is the maximum toy size
    // We need to find the smallest box size that can accommodate this toy
    long long maxToySize = A[0];
    for (int i = 0; i < N - 1; ++i) {
        if (B[i] >= maxToySize) {
            cout << maxToySize << endl;
            return 0;
        }
    }

    // If no box can be large enough, the smallest box size needed is one greater than the largest toy size
    cout << maxToySize + 1 << endl;

    return 0;
}