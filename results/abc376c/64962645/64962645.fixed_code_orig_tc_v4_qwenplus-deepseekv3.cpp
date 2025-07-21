#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];
    
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    
    int pos = -1;
    for (int i = 0; i < N; ++i) {
        if (i >= N - 1 || A[i] > B[i]) {
            pos = i;
            break;
        }
    }
    
    if (pos == -1) {
        cout << A.back() << endl;
        return 0;
    }
    
    int x = A[pos];
    vector<int> boxes;
    for (int b : B) boxes.push_back(b);
    boxes.push_back(x);
    sort(boxes.rbegin(), boxes.rend());
    
    int j = 0;
    bool possible = true;
    for (int i = 0; i < N; ++i) {
        if (j < boxes.size() && boxes[j] >= A[i]) {
            ++j;
        } else {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << x << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}