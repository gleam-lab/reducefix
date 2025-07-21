#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    while(true){
        bool flag=true;
        for(int i=0;i<N;i++){
            if(H[i]>0){
                flag=false;
                T++;
                H[i]--;
                if(i==0 && T%3==0){
                    H[i]-=2;
                }
            }
        }
        if(flag)break;
    }
    cout << T << endl;
    return 0;
}