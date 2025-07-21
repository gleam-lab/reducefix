#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N + 1); // Adjusted to use long long for handling large numbers
    for (int i = 1; i <= N; i++) cin >> H[i];
    long long T = 0;
    while(true){
        bool flag = false;
        for(int i=1;i<=N;i++){
            if(H[i]>0){
                T++;
                H[i]-=(T%3==0)?3:1;
                if(H[i]<=0) H[i]=0; // Set health to 0 if it becomes negative
                flag = true;
            }
        }
        if(!flag) break; // Break the loop if no enemy was attacked in this round
    }
    cout << T << endl;
    return 0;
}