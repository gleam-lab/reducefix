#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for(int i=0;i<N;i++) cin >> H[i]; // Index should start from 0 for C++
    long long T = 0;
    while(true){
        bool allZero=true;
        for(int i=0;i<N;i++){
            if(H[i]>0){
                allZero=false;
                if((T+1)%3==0) H[i]-=3;
                else H[i]-=1;
                T++;
            }
        }
        if(allZero) break; // Break loop once all enemies' health is reduced to 0 or less
    }
    cout << T << endl;
    return 0;
}