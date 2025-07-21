#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin>>n;
    vector<ll> h(n+9);
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    ll t=0;
    while(1){
        bool flag=true;
        for(int i=1;i<=n;i++){
            if(h[i]>0){
                flag=false;
                if(t%3==0){
                    h[i]-=3;
                }else{
                    h[i]--;
                }
                t++;
            }
        }
        if(flag){
            break;
        }
    }
    cout<<t<<endl;
    return 0;
}