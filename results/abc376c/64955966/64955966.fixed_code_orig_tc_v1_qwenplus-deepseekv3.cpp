#include<bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N-1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N-1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end(), greater<long long>());
    sort(B.begin(), B.end(), greater<long long>());
    
    int a_ptr = 0, b_ptr = 0;
    vector<bool> used(N-1, false);
    bool possible = true;
    
    while (a_ptr < N && b_ptr < N-1) {
        if (A[a_ptr] <= B[b_ptr]) {
            used[b_ptr] = true;
            a_ptr++;
            b_ptr++;
        } else {
            b_ptr++;
        }
    }
    
    if (a_ptr < N) {
        // Need to place remaining a_ptr..N-1 toys in the new box
        long long required_x = A[a_ptr];
        // Check if all remaining toys can fit into x: x must be >= all remaining toys
        for (int i = a_ptr + 1; i < N; ++i) {
            if (A[i] > required_x) {
                possible = false;
                break;
            }
        }
        if (possible) {
            cout << required_x << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        // All toys placed in existing boxes
        cout << 0 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}