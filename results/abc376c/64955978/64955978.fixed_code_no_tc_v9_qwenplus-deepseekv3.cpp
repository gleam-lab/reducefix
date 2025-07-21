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
    
    vector<bool> used(N-1, false);
    int box_ptr = 0;
    ll required_x = 0;
    
    for(int i = 0; i < N; i++) {
        if (box_ptr < N-1 && A[i] <= B[box_ptr]) {
            box_ptr++;
        } else {
            required_x = max(required_x, A[i]);
        }
    }
    
    if (required_x == 0) {
        // All toys fit into existing boxes; we can choose x as 1 (or any minimum)
        cout << 1 << endl;
    } else {
        // Check if the remaining boxes can accommodate the remaining toys when x is required_x
        bool possible = true;
        box_ptr = 0;
        int new_box_used = 0;
        
        for(int i = 0; i < N; i++) {
            if (box_ptr < N-1 && A[i] <= B[box_ptr]) {
                box_ptr++;
            } else if (A[i] <= required_x && new_box_used == 0) {
                new_box_used = 1;
            } else {
                possible = false;
                break;
            }
        }
        
        if (possible) {
            cout << required_x << endl;
        } else {
            cout << -1 << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}