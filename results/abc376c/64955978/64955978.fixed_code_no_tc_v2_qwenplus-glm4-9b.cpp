#include<bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }

    // Sort both arrays in descending order
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    // Initialize variables to determine the minimum box size x
    int min_x = 0;
    bool possible = true;

    // Iterate through all toys and existing boxes
    for (int i = 0; i < N; ++i) {
        // Start from the largest box that can possibly fit the toy
        int j = min(N - 2, i); // We only need to consider up to the second last box for the last toy

        // Find the largest box that can fit the toy
        while (j >= 0 && A[i] > B[j]) {
            --j;
        }

        // If no box can fit the toy, it's impossible to place all toys
        if (j < 0) {
            possible = false;
            break;
        }

        // Update the minimum box size x
        min_x = max(min_x, A[i]);
    }

    // If it's possible to place all toys, output the minimum box size x, otherwise output -1
    if (possible) {
        cout << min_x << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}