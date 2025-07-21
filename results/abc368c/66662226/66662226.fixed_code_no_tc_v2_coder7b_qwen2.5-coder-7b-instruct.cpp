#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n)
    {
        cin >> h[i];
    }
    ll t = 0;
    while(true){
        bool all_zero = true;
        rep(i,n){
            if(h[i]>0){
                all_zero = false;
                if((t+1)%3==0){
                    h[i]-=3;
                }else{
                    h[i]-=1;
                }
                t+=1;
            }
        }
        if(all_zero)break;
    }
    cout << t << endl;
}