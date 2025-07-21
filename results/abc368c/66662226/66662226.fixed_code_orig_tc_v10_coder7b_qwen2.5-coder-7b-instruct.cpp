#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<long long> h(n);
    rep(i, n) cin >> h[i];

    long long t = 0;
    while(true){
        bool flag = true;
        for(int i=0;i<n;i++){
            if(h[i]>0){
                flag=false;
                if((t+1)%3==0){
                    h[i]-=3;
                }else{
                    h[i]--;
                }
                t++;
                if(h[i]<=0) h[i]=0;
            }
        }
        if(flag) break;
    }

    cout<<t<<endl;
    return 0;
}