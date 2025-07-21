#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N-1);
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for(int i = 0; i < N-1; ++i) {
        cin >> B[i];
    }

    // Sort toys in descending order
    sort(A.begin(), A.end(), greater<long long>());
    // Sort boxes in descending order
    sort(B.begin(), B.end(), greater<long long>());

    // Initialize index for boxes
    int boxIndex = 0;

    // Try to place each toy into the largest available box
    for(int i = 0; i < N; ++i) {
        if(boxIndex < N-1 && A[i] <= B[boxIndex]) {
            // Toy fits into the current box
            continue;
        } else if(i + 1 < N && A[i] <= B[boxIndex]) {
            // Toy fits into the next box
            ++boxIndex;
            continue;
        } else {
            // Toy does not fit into any box
            cout << -1 << endl;
            return;
        }
    }

    // If we reach here, we found a valid box size
    cout << A.back() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}