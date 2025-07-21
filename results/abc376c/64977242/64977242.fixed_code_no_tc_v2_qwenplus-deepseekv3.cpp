#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N-1);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N-1; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    bool possible = true;
    for (int i = 0; i < N-1; i++) {
        if (A[i+1] > B[i]) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << -1 << endl;
    } else {
        cout << A[0] << endl;
    }

    return 0;
}