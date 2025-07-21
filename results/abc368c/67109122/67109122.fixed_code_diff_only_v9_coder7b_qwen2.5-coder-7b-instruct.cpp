#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N + 1); // Change size to N+1 to avoid index out of bounds
    for(int i = 1; i <= N; ++i)
        cin >> H[i];

    long long T = 0;
    while(true){
        bool attacked = false; // Flag to check if any enemy was attacked
        for(int i = 1; i <= N; ++i){
            if(H[i] > 0){ // Only attack if health is greater than 0
                attacked = true;
                if(T % 3 == 0)
                    H[i] -= 3;
                else
                    H[i] -= 1;
                ++T;
            }
        }
        if(!attacked) break; // Break loop if no enemy was attacked in the current iteration
    }

    cout << T << endl;
    return 0;
}