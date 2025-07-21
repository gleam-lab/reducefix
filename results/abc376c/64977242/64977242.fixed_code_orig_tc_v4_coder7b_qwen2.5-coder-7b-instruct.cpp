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

    int minBoxSize = 0;
    for (int i = 0; i < N - 1; i++) {
        if (A[i] > B[i]) {
            minBoxSize = max(minBoxSize, (int)(A[i] + B[i]));
        }
    }

    if (minBoxSize == 0) {
        cout << -1 << endl;
    } else {
        cout << minBoxSize << endl;
    }

    return 0;
}