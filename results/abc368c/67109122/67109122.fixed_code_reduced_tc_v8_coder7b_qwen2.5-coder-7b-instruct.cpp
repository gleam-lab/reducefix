#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    long long t=0;
    while(1){
        bool flag=false;
        for(int i=1;i<=n;i++){
            if(v[i]>0){
                flag=true;
                if(t%3==0)v[i]-=3;
                else v[i]--;
                t++;
            }
        }
        if(!flag)break;
    }
    cout<<t<<endl;
    return 0;
}