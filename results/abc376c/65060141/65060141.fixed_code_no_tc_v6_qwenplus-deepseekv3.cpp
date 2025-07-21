#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N],b[N];
int main(){
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<n;i++){
        cin>>b[i];
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n);
    ll toys_left = 0;
    ll max_unplaced = 0;
    ll i = n, j = n-1;
    while(i >= 1 && j >= 1){
        if(b[j] >= a[i]){
            j--;
            i--;
        } else {
            max_unplaced = max(max_unplaced, a[i]);
            toys_left++;
            i--;
        }
    }
    while(i >= 1){
        max_unplaced = max(max_unplaced, a[i]);
        toys_left++;
        i--;
    }
    if(toys_left > 1){
        cout << -1;
    } else {
        cout << max_unplaced;
    }
    return 0;
}