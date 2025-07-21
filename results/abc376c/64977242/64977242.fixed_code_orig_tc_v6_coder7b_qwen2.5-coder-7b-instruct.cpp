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

    // Find the smallest x such that we can place all toys in the boxes
    for (int i = 0; i < N - 1; i++) {
        if (A[i] > B[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    // The largest box needed will be the maximum of the remaining toys' sizes
    long long maxX = *max_element(A.begin() + (N - 1), A.end());

    cout << maxX << endl;

    return 0;
}