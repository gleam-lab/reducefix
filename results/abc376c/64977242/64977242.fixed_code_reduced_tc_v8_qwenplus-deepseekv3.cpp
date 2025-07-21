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

    // Check if the largest N-1 toys can fit into the N-1 boxes
    bool possible = true;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i + 1] > B[i]) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        // The largest toy must go into the new box
        sort(A.begin(), A.end(), greater<long long>());
        sort(B.begin(), B.end(), greater<long long>());
        possible = true;
        for (int i = 0; i < N - 1; ++i) {
            if (A[i + 1] > B[i]) {
                possible = false;
                break;
            }
        }
        if (possible) {
            cout << A[0] << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        // The smallest toy can go into the new box
        cout << A[0] << endl;
    }

    return 0;
}