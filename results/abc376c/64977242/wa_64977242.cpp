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

    bool canStore = true;
    for (int i = 0; i < N - 1; i++) {
        if (A[i] > B[i]) {
            canStore = false;
        }
    }

    if (!canStore) {
        cout << -1 << endl;
        return 0;
    }

    sort(A.begin(), A.end(), std::greater<long long>());
    sort(B.begin(), B.end(), std::greater<long long>());

    long long targetValue = 0;
    for (int i = 0; i < N - 1; i++) {
        if (A[i] > B[i]) {
            targetValue = A[i];
            break;
        }
    }

    if (targetValue == 0) targetValue = *A.end() - 1;

    cout << targetValue << endl;

    return 0;
}
