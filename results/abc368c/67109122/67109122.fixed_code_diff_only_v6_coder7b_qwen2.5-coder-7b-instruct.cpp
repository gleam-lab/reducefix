#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> h(n+9); for(int i=1;i<=n;i++)cin>>h[i];
    long long t=0;
    while(1){
        bool flag=true;
        for(int i=1;i<=n;i++){
            if(h[i]>0){
                flag=false;
                if(t%3==0)h[i]-=3;
                else h[i]--;
                t++;
            }
        }
        if(flag)break;
    }
    cout<<t<<endl;
    return 0;
}