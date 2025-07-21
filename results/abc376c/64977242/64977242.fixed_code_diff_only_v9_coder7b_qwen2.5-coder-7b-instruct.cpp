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

    // Check if the largest toy can fit in any of the existing boxes
    for (int i = N - 1; i >= 0; i--) {
        if (A[i] <= B[N - 2 - i]) {
            cout << B[N - 2 - i] + 1 << endl;
            return 0;
        }
    }

    // If no box can fit the largest toy, we need to buy a new box
    cout << A[N - 1] << endl;

    return 0;
}