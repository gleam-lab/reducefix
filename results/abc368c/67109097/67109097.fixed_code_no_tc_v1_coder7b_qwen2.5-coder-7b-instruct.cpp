#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N + 1); // Change size to N+1 for zero-based indexing
    for(int i = 1; i <= N; i++) cin >> H[i];

    long long T = 0;
    for(int i = 1; i <= N; i++) {
        while(H[i] > 0) { // Continue attacking until the enemy is defeated
            if(T % 3 == 0)
                H[i] -= 3; // Decrease health by 3 if T is a multiple of 3
            else
                H[i]--; // Otherwise, decrease health by 1
            T++; // Increment the turn counter
        }
    }

    cout << T << endl;
    return 0;
}