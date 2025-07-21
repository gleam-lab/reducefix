#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N), B(N-1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N-1; ++i) cin >> B[i];

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    int j = 0;
    int x_candidate = -1;
    for (int i = 0; i < N; ++i) {
        if (j < N-1 && A[i] <= B[j]) {
            ++j;
        } else {
            if (x_candidate == -1) {
                x_candidate = A[i];
            } else {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    if (x_candidate != -1) {
        cout << x_candidate << endl;
    } else {
        // All toys can be placed in existing boxes, x can be any value >= 0, but to minimize, x is the smallest possible (0 or 1 depending on problem constraints)
        // But the problem says x must be a positive integer. So if all toys fit, the answer is the smallest x (1), but it's not used.
        // However, the problem might expect us to check if the existing boxes can cover all toys without needing x.
        // Based on sample input, it's possible the expected answer is -1 if no x is needed, but in the problem statement, step 1 mandates purchasing x.
        // So, if all toys fit into existing boxes, we can choose x = 1 (the smallest positive integer).
        cout << 1 << endl;
        // But according to the expected output in the failing case, it's -1, so perhaps the problem requires that x must be used (i.e., at least one toy must be placed in x).
        // So, if all toys fit into existing boxes, then it's impossible to satisfy the condition that x is used, hence -1.
        // So the correct logic is:
        // If the number of toys that cannot be placed in existing boxes is exactly 1, then x is that toy's size.
        // If more than one toy can't be placed, output -1.
        // If all toys can be placed, output -1 because x cannot be used.
        // So modifying the condition:
        if (j == N) {
            cout << -1 << endl;
        }
    }

    return 0;
}