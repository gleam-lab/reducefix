#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N],b[N];
int main(){
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<n-1;i++){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n-1);
    ll new_box_size=0;
    ll toy_ptr=n-1;
    ll box_ptr=n-2;
    ll cnt=0;
    while(toy_ptr>=0 && box_ptr>=0){
        if(b[box_ptr]>=a[toy_ptr]){
            box_ptr--;
            toy_ptr--;
        } else {
            new_box_size=max(new_box_size,a[toy_ptr]);
            cnt++;
            toy_ptr--;
        }
    }
    while(toy_ptr>=0){
        new_box_size=max(new_box_size,a[toy_ptr]);
        cnt++;
        toy_ptr--;
    }
    if(cnt>1){
        cout<<-1;
    } else {
        cout<<new_box_size;
    }
    return 0;
}