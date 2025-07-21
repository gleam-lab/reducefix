#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A, B;

int main() {
    cin >> N;
    A.resize(N);
    B.resize(N-1);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    int maxSize = 0;
    for (int i = 0; i < N - 1; i++) {
        maxSize = max(maxSize, max(A[i], B[i]));
    }

    cout << maxSize << endl;

    return 0;
}