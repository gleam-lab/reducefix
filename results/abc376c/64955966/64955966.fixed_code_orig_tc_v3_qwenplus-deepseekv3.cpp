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
    
    multiset<ll> boxes(B.begin(), B.end());
    ll x = -1;
    
    for(int i = 0; i < N; i++) {
        auto it = boxes.lower_bound(A[i]);
        if(it != boxes.end()) {
            boxes.erase(it);
        } else {
            if(x == -1) {
                x = A[i];
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }
    
    cout << x << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}