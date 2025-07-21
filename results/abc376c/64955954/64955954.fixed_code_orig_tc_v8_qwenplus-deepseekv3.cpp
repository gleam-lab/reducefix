#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    vector<int> matched;
    int j = 0;
    for (int i = 0; i < N - 1; ++i) {
        while (j < N && A[j] > B[i]) ++j;
        if (j < N) {
            matched.push_back(A[j]);
            ++j;
        } else {
            break;
        }
    }
    
    if (matched.size() < N - 1) {
        cout << -1 << endl;
        return 0;
    }
    
    int remaining = -1;
    j = 0;
    for (int i = 0; i < N; ++i) {
        if (j < matched.size() && A[i] == matched[j]) {
            ++j;
        } else {
            remaining = A[i];
        }
    }
    
    if (remaining == -1) {
        cout << -1 << endl;
    } else {
        cout << remaining << endl;
    }
    
    return 0;
}