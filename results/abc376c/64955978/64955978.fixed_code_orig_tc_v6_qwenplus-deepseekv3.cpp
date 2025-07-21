#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N), B(N-1);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N-1; ++i) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // We need to match N toys to N boxes (N-1 existing + 1 new)
    // The optimal strategy is to match the largest N-1 toys with the largest N-1 boxes
    // Then the remaining toy must fit in the new box

    // Match largest N-1 toys to largest N-1 boxes
    bool possible = true;
    for (int i = 0; i < N-1; ++i) {
        if (A[i+1] > B[i]) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << -1 << '\n';
        return 0;
    }

    // The smallest possible x is the first toy that wasn't matched
    // which is the smallest toy (A[0]) since we sorted in ascending order
    // But wait - we need to find which toy is left out after matching N-1 toys

    // Alternative approach: after matching largest N-1 toys to largest N-1 boxes,
    // the remaining toy is the smallest one (A[0])
    cout << A[0] << '\n';
}