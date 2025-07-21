#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;
    int t = 0;
    while(true){
        bool flag = false;
        rep(i,n){
            if(a[i]>0){
                flag = true;
                if((t+1)%3==0)a[i]-=3;
                else a[i]--;
                ans++;
                if(a[i]<=0)a[i]=0;
            }
        }
        if(!flag)break;
        t++;
    }
    cout << ans << endl;
}