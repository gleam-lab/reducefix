#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<long long> h(n);
    for(int i=0; i<n; ++i) cin >> h[i];

    long long t = 0;
    while(true){
        bool flag = false;
        for(int i=0; i<n; ++i){
            if(h[i]>0){
                flag = true;
                if((t+1)%3==0) h[i]-=3;
                else h[i]--;
                if(h[i]<0) h[i]=0;
                t++;
            }
        }
        if(!flag) break;
    }

    cout << t << '\n';
    return 0;
}