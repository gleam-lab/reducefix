#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll N;
    cin >> N;
    vector<ll> A(N), B(N-1);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N-1; i++) cin >> B[i];
    
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());
    
    int i = 0, j = 0;
    ll x = -1;
    while(i < N && j < N-1){
        if(A[i] <= B[j]){
            i++;
            j++;
        } else {
            if(x == -1){
                x = A[i];
                i++;
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }
    
    if(i < N){
        if(x == -1){
            x = A[i];
        } else {
            cout << -1 << endl;
            return;
        }
    }
    
    if(x == -1){
        x = 1; // All toys fit into existing boxes, so any x >= 1 is possible, smallest is 1
    }
    
    cout << x << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}