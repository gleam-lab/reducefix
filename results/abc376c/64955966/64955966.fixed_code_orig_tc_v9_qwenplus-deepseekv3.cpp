#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    // We need to assign each A[i] to a box >= A[i], with one box being x (newly purchased)
    // The boxes are B[0..N-2] and x.
    // The problem reduces to finding the smallest x such that:
    // After sorting A and B, for all i < N-1, A[i] <= B[i], and A[N-1] <= x.
    // Or, if there's one mismatch where A[i] > B[i], then that A[i] must be assigned to x.
    
    // So, find the smallest x that is >= A[N-1], and check if the other N-1 toys can fit into the other N-1 boxes.
    // Then, x can be A[N-1], but we need to ensure that the other N-1 toys fit into B.
    
    // Alternative approach: find the largest A[i] that cannot be matched to any B[j] >= A[i], and x must be >= that A[i].
    // So, the minimal x is the maximum of such A[i] that cannot be matched.
    
    // Strategy: try to match the largest N-1 toys to the largest N-1 boxes (B), and the remaining toy must fit into x.
    
    // The minimal x is the maximum between:
    // - The largest A[i] not matched to any B[j] >= A[i] in the first N-1 toys.
    // - The remaining toy (A[N-1]) if it cannot be matched to any B[j] >= A[N-1].
    
    int i = N - 1;
    int j = N - 2;
    long long x_min = 0;
    
    while (i >= 0 && j >= 0) {
        if (A[i] <= B[j]) {
            --i;
            --j;
        } else {
            x_min = A[i];
            break;
        }
    }
    
    if (i >= 0 && j < 0) {
        x_min = max(x_min, A[i]);
    }
    
    // Now, check if all other toys can be matched to the boxes without x.
    // We have to use N-1 boxes (from B) to match N-1 toys (excluding the one that requires x).
    
    bool possible = true;
    i = 0;
    j = 0;
    int count = 0;
    while (i < N && j < N - 1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
            ++count;
        } else {
            ++j;
        }
    }
    
    if (count >= N - 1) {
        possible = true;
    } else {
        possible = false;
    }
    
    if (!possible) {
        cout << -1 << endl;
    } else {
        cout << x_min << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}