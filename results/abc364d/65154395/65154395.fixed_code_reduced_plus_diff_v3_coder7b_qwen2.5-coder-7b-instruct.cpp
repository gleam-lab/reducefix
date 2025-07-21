#include<bits/stdc++.h>
using namespace std;

vector<int> A, B;

int main() {
    int N, Q;
    cin >> N >> Q;
    A.resize(N); 
    B.resize(Q);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < Q; i++) {
        cin >> B[i];
    }

    vector<int> res(Q);
    
    for(int i = 0; i < Q; i++) {
        sort(A.begin(), A.end());
        int diff = abs(B[i] - A[k-1]);
        for(int j = 0; j < N; j++) {
            A[j] -= diff;
        }
    }
  
    for(int i = 0; i < Q; i++) {
        cout << A[k-1] << endl;
    }

    return 0;
}