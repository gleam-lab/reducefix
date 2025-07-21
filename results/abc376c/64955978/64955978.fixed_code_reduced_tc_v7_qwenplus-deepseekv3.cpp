#include<bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N-1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N-1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    int box_ptr = 0;
    vector<bool> box_used(N-1, false);
    vector<int> remaining_toys;
    
    for (int toy : A) {
        while (box_ptr < N-1 && (box_used[box_ptr] || B[box_ptr] < toy)) {
            ++box_ptr;
        }
        if (box_ptr < N-1 && !box_used[box_ptr] && B[box_ptr] >= toy) {
            box_used[box_ptr] = true;
        } else {
            remaining_toys.push_back(toy);
        }
    }
    
    if (remaining_toys.size() > 1) {
        cout << -1 << endl;
        return;
    } else if (remaining_toys.empty()) {
        cout << 0 << endl; // or any value since all toys are placed, but problem says x must be positive
        // But according to the problem statement, we need to purchase a box (x > 0), so if all toys fit in existing boxes, the minimal x is 1.
        cout << 1 << endl;
        return;
    } else {
        cout << remaining_toys[0] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}