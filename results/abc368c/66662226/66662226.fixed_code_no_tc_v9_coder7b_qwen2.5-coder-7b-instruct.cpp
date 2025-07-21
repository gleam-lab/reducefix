#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    ll ans = 0;
    rep(i, n)
    {
        cin >> a[i];
    }
    while(true){
        bool flag=true;
        rep(i,n){
            if(a[i]>0){
                flag=false;
                break;
            }
        }
        if(flag)break;
        ans++;
        rep(i,n){
            if(a[i]>0){
                if(ans%3==0)a[i]-=3;
                else a[i]--;
            }
        }
    }
    cout << ans << endl;
}