#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long N;
    cin >> N;
    vector<long long> A(N), B(N - 1);
    for (long long i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (long long i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }

    // Sort the toy sizes in ascending order and the box sizes in descending order
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<long long>());

    // Check if the largest box can fit the largest toy
    if (A[N - 1] > B[0]) {
        cout << -1 << endl;
        return 0;
    }

    // Determine the minimum box size x by checking the smallest box size that can fit all toys
    long long x = 1;
    for (long long i = 0; i < N; ++i) {
        if (A[i] > x) {
            x = A[i];
        }
    }

    cout << x << endl;
    return 0;
}