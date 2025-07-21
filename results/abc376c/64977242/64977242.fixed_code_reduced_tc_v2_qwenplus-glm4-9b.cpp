#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);

    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    // Sort the sizes of toys and boxes
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // If the smallest toy cannot fit in the smallest box, print -1
    if (A[0] > B[0]) {
        cout << -1 << endl;
    } else {
        // The minimum size of the box needed is the size of the largest toy
        cout << A[N - 1] << endl;
    }

    return 0;
}