#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<long long> h(n+1);
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }

    long long t=0;
    while(true){
        bool flag=true;
        for(int i=1;i<=n;i++){
            if(h[i]>0){
                flag=false;
                if(t%3==0){
                    h[i]-=3;
                }else{
                    h[i]--;
                }
                t++;
                if(h[i]<=0){
                    h[i]=0;
                }
            }
        }
        if(flag){
            break;
        }
    }

    cout<<t<<endl;
    return 0;
}