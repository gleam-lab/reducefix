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
    
    int x_candidate = -1;
    int i = 0, j = 0;
    while (i < N && j < N-1) {
        if (A[i] <= B[j]) {
            i++;
            j++;
        } else {
            if (x_candidate == -1) {
                x_candidate = A[i];
                i++;
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }
    
    if (i < N) {
        if (x_candidate == -1) {
            x_candidate = A[i];
        } else {
            cout << -1 << endl;
            return;
        }
    }
    
    if (x_candidate == -1) {
        cout << 1 << endl; // All toys can be placed in existing boxes; smallest x is 1
    } else {
        // Check if remaining toys can be placed in remaining boxes or the new box
        bool possible = true;
        int new_box = x_candidate;
        vector<int> remaining_toys;
        for (int k = i; k < N; ++k) {
            remaining_toys.push_back(A[k]);
        }
        sort(remaining_toys.begin(), remaining_toys.end(), greater<int>());
        vector<int> remaining_boxes;
        for (int k = j; k < N-1; ++k) {
            remaining_boxes.push_back(B[k]);
        }
        remaining_boxes.push_back(new_box);
        sort(remaining_boxes.begin(), remaining_boxes.end(), greater<int>());
        
        if (remaining_toys.size() > remaining_boxes.size()) {
            possible = false;
        } else {
            for (int k = 0; k < remaining_toys.size(); ++k) {
                if (remaining_toys[k] > remaining_boxes[k]) {
                    possible = false;
                    break;
                }
            }
        }
        
        if (possible) {
            cout << x_candidate << endl;
        } else {
            cout << -1 << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}