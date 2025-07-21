#include<iostream>
#include<vector>
using namespace std;

long long solve(int n, vector<int> h){
    long long t = 0;
    while(true){
        bool done = true;
        for(int i=0;i<n;i++){
            if(h[i]>0){
                done = false;
                if((t+1)%3==0){
                    h[i]-=3;
                }else{
                    h[i]--;
                }
                t++;
            }
        }
        if(done) break;
    }
    return t;
}

int main(){
    int n;
    cin>>n;
    vector<int> h(n);
    for(int i=0;i<n;i++) cin>>h[i];
    cout<<solve(n,h)<<endl;
    return 0;
}