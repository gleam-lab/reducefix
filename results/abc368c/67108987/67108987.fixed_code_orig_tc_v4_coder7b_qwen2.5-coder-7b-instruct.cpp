#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N + 1); // Changed type to long long to handle large numbers
    for(int i = 1; i <= N; ++i) cin >> H[i];
    
    long long T = 0;
    while(true) {
        bool allZero = true;
        for(int i = 1; i <= N; ++i) {
            if(H[i] > 0) {
                allZero = false;
                if(T % 3 == 0) {
                    H[i] -= 3;
                } else {
                    H[i]--;
                }
                ++T;
                break; // Only one attack per round
            }
        }
        if(allZero) break;
    }
    cout << T << endl;
    return 0;
}