#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll N;
    cin >> N;
    vector<ll> A(N), B(N-1);
    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }
    for(ll i = 0; i < N-1; i++){
        cin >> B[i];
    }

    // We need to find the smallest box size x that can fit all toys
    // considering the existing boxes and one additional box of size x.

    // Sort the toy sizes in descending order and box sizes in descending order
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());

    // We can either take the last box size (B[N-2] when N > 1) as the base size
    // or we need to find the next smallest box size that can fit the largest toy.
    ll min_x = (N > 1) ? B[N-2] : LLONG_MAX;

    // Iterate over the existing boxes and find the smallest box size that
    // can fit the largest toy we have currently considered.
    for(ll i = 0; i < N; i++){
        if(A[i] <= min_x){
            break;
        }
        min_x = B[i];
    }

    // If the last toy can fit in any of the existing boxes, min_x will be equal to the base box size,
    // otherwise we need to find a bigger box to fit this last toy.
    if(A[N-1] <= min_x){
        cout << min_x << endl;
    } else {
        cout << (A[N-1] + 1) << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}