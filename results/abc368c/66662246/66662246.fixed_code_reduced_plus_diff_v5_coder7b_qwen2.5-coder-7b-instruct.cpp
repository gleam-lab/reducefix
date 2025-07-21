#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;
    for(int i=0;i<n;i++){
        if(a[i]>0){
            int cnt=a[i]/3;
            if(a[i]%3!=0)cnt++;
            ans+=cnt;
            a[i]-=cnt*3;
        }
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int i=0;
    while(i<n && a[i]==0)i++;
    while(i<n){
        int cnt=a[i]/3;
        if(a[i]%3!=0)cnt++;
        ans+=cnt;
        a[i]-=cnt*3;
        for(int j=i+1;j<n;j++){
            if(a[j]>=cnt){
                a[j]-=cnt;
                break;
            }else{
                cnt-=a[j];
                a[j]=0;
            }
        }
        i++;
    }
    cout << ans << endl;
}