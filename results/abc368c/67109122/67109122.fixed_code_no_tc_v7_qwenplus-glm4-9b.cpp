#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    for (int i = 0; i < N; i++) {
        // Calculate the number of full attacks of 3 and remaining health
        int fullAttacks = H[i] / 3;
        int remainingHealth = H[i] % 3;
        
        // Update T by the number of full attacks, considering if T was initially a multiple of 3
        T += (3 * fullAttacks + remainingHealth);
    }
    
    cout << T << endl;
    return 0;
}