#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for(int i = 0; i < N; ++i) cin >> H[i];
    long long T = 0;
    while(true) {
        bool anyAlive = false;
        for(int i = 0; i < N; ++i) {
            if(H[i] > 0) {
                anyAlive = true;
                if((T+1)%3 == 0) H[i] -= 3;
                else H[i] -= 1;
                if(H[i] < 0) H[i] = 0;
                T++;
            }
        }
        if(!anyAlive) break;
    }
    cout << T << endl;
    return 0;
}