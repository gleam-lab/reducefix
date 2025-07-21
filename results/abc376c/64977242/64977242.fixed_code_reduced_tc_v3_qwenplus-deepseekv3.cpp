#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<bool> used(N - 1, false);
    int j = 0;
    bool possible = true;
    for (int i = 0; i < N - 1; ++i) {
        while (j < N - 1 && B[j] < A[i]) {
            ++j;
        }
        if (j >= N - 1) {
            possible = false;
            break;
        }
        used[j] = true;
        ++j;
    }

    if (!possible) {
        cout << -1 << endl;
        return 0;
    }

    long long x = A.back();
    for (int i = 0; i < N - 1; ++i) {
        if (!used[i] && B[i] >= x) {
            x = min(x, B[i]);
        }
    }

    for (int i = 0; i < N - 1; ++i) {
        if (!used[i]) {
            x = max(x, A.back());
            break;
        }
    }

    cout << x << endl;

    return 0;
}