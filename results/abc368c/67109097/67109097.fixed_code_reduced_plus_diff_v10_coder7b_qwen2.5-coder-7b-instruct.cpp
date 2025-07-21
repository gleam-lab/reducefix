#include<bits/stdc++.h>
using namespace std;

long long solve(vector<long long>& h) {
    long long t = 0;
    while(true){
        bool changed = false;
        for(int i=0;i<h.size();i++){
            if(h[i]>0){
                if((t+1)%3==0){
                    h[i]-=3;
                }else{
                    h[i]--;
                }
                changed = true;
                if(h[i]<0)h[i]=0;
            }
        }
        t++;
        if(!changed)return t-1;
    }
}

int main(){
    int n;
    cin>>n;
    vector<long long> h(n);
    for(int i=0;i<n;i++)cin>>h[i];
    cout<<solve(h)<<endl;
    return 0;
}