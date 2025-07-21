#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N-1);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    for (int i = 0; i < N-1; ++i) {
        cin >> B[i];
    }
    
    // Sort toys and boxes in ascending order
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    // Iterate through each toy and try to find a suitable box
    for (int i = 0; i < N; ++i) {
        bool found = false;
        for (int j = 0; j < N-1; ++j) {
            if (!found && A[i] <= B[j]) {
                found = true;
                B[j] = -1; // Mark this box as used
                break;
            }
        }
        if (!found) {
            cout << -1 << endl;
            return;
        }
    }
    
    // Find the smallest box size that was used
    int min_box_size = INT_MAX;
    for (int b : B) {
        if (b != -1) {
            min_box_size = min(min_box_size, b);
        }
    }
    
    cout << min_box_size << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}