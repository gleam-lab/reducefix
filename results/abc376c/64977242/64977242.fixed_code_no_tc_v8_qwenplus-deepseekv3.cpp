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
    int last_unmatched = -1;

    int i = 0, j = 0;
    while (i < N && j < N - 1) {
        if (A[i] <= B[j]) {
            used[j] = true;
            ++i;
            ++j;
        } else {
            ++j;
        }
    }

    if (i < N) {
        last_unmatched = i;
    } else {
        cout << 0 << endl;
        return 0;
    }

    long long x = A[last_unmatched];

    for (int k = last_unmatched + 1; k < N; ++k) {
        if (A[k] > x) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << x << endl;

    return 0;
}