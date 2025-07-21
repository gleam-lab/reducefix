#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<long long> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    long long t=0;
    while(true){
        bool done=true;
        for(int i=1;i<=n;i++){
            if(v[i]>0){
                done=false;
                break;
            }
        }
        if(done)break;
        t++;
        for(int i=1;i<=n;i++){
            if(v[i]>0){
                if(t%3==0)v[i]-=3;
                else v[i]--;
            }
        }
    }
    cout<<t<<endl;
    return 0;
}