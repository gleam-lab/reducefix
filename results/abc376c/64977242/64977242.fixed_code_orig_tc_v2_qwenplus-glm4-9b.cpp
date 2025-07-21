#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin >> N;
    vector<long long> A(N), B(N - 1);

    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    sort(A.begin(), A.end());
    long long minX = A.back();
    for (int i = 0; i < N; i++) {
        bool fit = false;
        for (int j = 0; j < N - 1 && B[j] >= A[i]; j++) {
            fit = true;
            break;
        }
        if (fit) {
            minX = min(minX, A[i]);
        }
    }

    if (minX == A.back()) {
        cout << -1 << endl;
    } else {
        cout << minX << endl;
    }

    return 0;
}