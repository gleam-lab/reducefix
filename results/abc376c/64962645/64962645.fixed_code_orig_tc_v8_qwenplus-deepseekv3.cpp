#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N - 1);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    int k = -1;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > B[i]) {
            k = i;
            break;
        }
    }
    if (k == -1) {
        cout << 1 << endl;
        return 0;
    }
    
    int x_candidate = A[k];
    vector<int> newB = B;
    newB.push_back(x_candidate);
    sort(newB.begin(), newB.end(), greater<int>());
    
    bool possible = true;
    for (int i = 0; i < N; ++i) {
        if (A[i] > newB[i]) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << x_candidate << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}