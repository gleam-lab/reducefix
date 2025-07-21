#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long> h(n+9);
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    long long t=0;
    for(int i=1;i<=n;i++){
        if(h[i]>0){
            if(t%3==0)t+=(h[i]+2)/3;
            else t+=(h[i]+1)/2;
        }
    }
    cout<<t<<endl;
    return 0;
}