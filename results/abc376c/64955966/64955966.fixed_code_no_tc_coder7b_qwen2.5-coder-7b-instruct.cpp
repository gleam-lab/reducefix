#include<bits/stdc++.h>
using namespace std;

void solve(){
    int N;
    cin >> N;
    vector<int> A(N), B(N-1);
    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < N-1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    int x = -1, j = 0;
    for(int i = 0; i < N-1; ++i){
        if(A[i] <= B[j]){
            j++;
        } else {
            x = max(x, A[i]);
        }
    }

    if(j == N-1) cout << -1 << endl;
    else cout << max(x, A[N-1]) << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}