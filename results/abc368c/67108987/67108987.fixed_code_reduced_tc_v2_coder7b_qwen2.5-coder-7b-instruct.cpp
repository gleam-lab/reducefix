#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N + 9);
    for (int i = 1; i <= N; i++) cin >> H[i];
    long long T = 0;
    while(true){
        bool flag=false;
        for(int i=1;i<=N;i++){
            if(H[i]>0){
                flag=true;
                if((T+1)%3==0) H[i]-=3;
                else H[i]--;
                T++;
            }
        }
        if(!flag) break;
    }
    cout<<T<<endl;
    return 0;
}