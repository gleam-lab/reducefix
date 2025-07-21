#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n; cin >> n;
    vector<ll> h(n+1), s(n+1);

    for(int i=1;i<=n;++i){
        cin >> h[i];
        s[i]=s[i-1]+h[i];
    }

    ll t=0, j=1;
    while(j<=n){
        if(h[j]>0){
            ll need=h[j]/5;
            if(h[j]%5!=0) ++need;
            t+=need*3;
            if(s[n]-s[j]>=need*5){
                h[j]=0;
                j++;
            }
            else{
                ll k=j;
                while(k<=n && s[n]-s[k]<need*5){
                    need-=((s[n]-s[k])/5);
                    k++;
                }
                if(k>j){
                    t+=(k-j)*3;
                    h[j]=s[k-1]-s[j]+1;
                    j=k;
                }
                else{
                    t+=(s[n]-s[j])*3/h[j];
                    h[j]=0;
                    j=n+1;
                }
            }
        }
        else j++;
    }

    cout << t << '\n';
    return 0;
}