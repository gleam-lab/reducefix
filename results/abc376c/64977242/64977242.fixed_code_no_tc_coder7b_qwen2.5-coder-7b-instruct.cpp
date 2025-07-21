#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N-1);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long x = 0;
    for (int i = 0, j = 0; i < N; i++) {
        if (j < N - 1 && A[i] <= B[j]) {
            j++;
        } else {
            x = max(x, A[i]);
        }
    }

    cout << (x == 0 ? -1 : x) << endl;

    return 0;
}