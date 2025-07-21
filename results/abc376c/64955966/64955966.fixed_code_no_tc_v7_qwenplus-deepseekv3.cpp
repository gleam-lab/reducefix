#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll N;
    cin >> N;
    vector<ll> a(N), b(N-1);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < N-1; i++){
        cin >> b[i];
    }
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());

    int j = 0;
    vector<bool> used(N-1, false);
    ll x_needed = -1;
    for(int i = 0; i < N; i++){
        while(j < N-1 && (used[j] || b[j] < a[i])){
            j++;
        }
        if(j < N-1){
            used[j] = true;
        } else {
            if(x_needed == -1 || a[i] > x_needed){
                x_needed = a[i];
            }
        }
    }

    if(x_needed == -1){
        cout << 1 << endl;
    } else {
        cout << x_needed << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}