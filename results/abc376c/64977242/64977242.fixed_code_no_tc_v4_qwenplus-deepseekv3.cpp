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

    vector<bool> matched(N - 1, false);
    int j = 0;
    for (int i = 0; i < N - 1; ++i) {
        while (j < N && A[j] <= B[i]) {
            ++j;
        }
        if (j == N) {
            cout << -1 << endl;
            return 0;
        }
        matched[i] = true;
        ++j;
    }

    long long x = -1;
    for (int i = 0; i < N; ++i) {
        bool found = false;
        for (int k = 0; k < N - 1; ++k) {
            if (B[k] >= A[i] && !matched[k]) {
                matched[k] = true;
                found = true;
                break;
            }
        }
        if (!found) {
            x = A[i];
            break;
        }
    }

    if (x == -1) {
        cout << -1 << endl;
    } else {
        cout << x << endl;
    }

    return 0;
}