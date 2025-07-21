#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for(int i=0; i<N; i++) cin >> H[i];

    long long T = 0;
    while(true){
        bool all_zero = true;
        for(int i=0; i<N; i++){
            if(H[i]>0){
                all_zero = false;
                if((T+1)%3==0) H[i]-=3;
                else H[i]--;
                T++;
            }
        }
        if(all_zero) break;
    }

    cout << T << endl;
    return 0;
}