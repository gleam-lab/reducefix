#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define sp ' '
using namespace std;

void solve(){
    ll N;
    cin >> N;
    vector<ll> a(N), b(N-1);
    for(int i=0; i<N; i++){
        cin >> a[i];
    }
    for(int i=0; i<N-1; i++){
        cin >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll mx = *max_element(a.begin(), a.end());
    bool found = false;

    for(ll i = mx; i <= 1e9; i++){
        int j = 0, k = 0;
        while(j < N && k < N-1){
            if(a[j] <= i && a[j] >= b[k]){
                j++; k++;
            }else if(a[j] > i || a[j] < b[k]){
                break;
            }
        }
        if(j == N && k == N-1){
            found = true;
            cout << i << endl;
            return;
        }
    }

    if(!found){
        cout << -1 << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}