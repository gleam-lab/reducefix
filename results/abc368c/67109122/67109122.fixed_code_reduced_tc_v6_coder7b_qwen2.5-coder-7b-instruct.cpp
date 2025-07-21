#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> h(n+1);
    for(int i=1;i<=n;i++) cin >> h[i];

    long long t = 0;
    while(1){
        bool flag = false;
        for(int i=1;i<=n;i++){
            if(h[i]>0){
                flag = true;
                if(t%3==0) h[i]-=3;
                else h[i]-=1;
                t++;
            }
        }
        if(!flag) break;
    }

    cout<<t<<endl;
    return 0;
}