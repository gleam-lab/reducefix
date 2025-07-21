#include<bits/stdc++.h>
using namespace std;

vector<int> A, B;

int main() {
    int N, Q;
    cin >> N >> Q;
    
    A.resize(N + 1);
    B.resize(Q);
    
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    for(int i = 0; i < Q; i++) {
        cin >> B[i].first >> B[i].second;
    }
    
    for(int i = 0; i < Q; i++) {
        int pos = upper_bound(A.begin(), A.end(), B[i].first) - A.begin();
        int ans = 0;
        
        if(pos == 0) {
            ans = abs(B[i].first - A[pos]);
        } else if(pos == N + 1) {
            ans = abs(B[i].first - A[pos - 1]);
        } else {
            ans = min(abs(B[i].first - A[pos]), abs(B[i].first - A[pos - 1]));
        }
        
        cout << ans * B[i].second << endl;
    }
    
    return 0;
}