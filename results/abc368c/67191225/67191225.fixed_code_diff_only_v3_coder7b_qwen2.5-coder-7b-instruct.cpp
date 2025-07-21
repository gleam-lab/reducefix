#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> h(n);
    for(int i=0;i<n;++i){
        cin>>h[i];
    }
    
    long long t = 0;
    while(true){
        bool done = true;
        for(int i=0;i<n;++i){
            if(h[i]>0){
                --h[i];
                ++t;
                done = false;
                if(t%3==0 && h[i]==0){
                    ++h[i];
                }
            }
        }
        if(done){
            break;
        }
    }

    cout<<t<<endl;
    return 0;
}