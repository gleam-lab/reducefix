#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N + 1);
    for (int i = 1; i <= N; i++) cin >> H[i];
    
    long long T = 0;
    
    for (int i = 1; i <= N; i++) {
        // Determine how many full attack cycles we can perform on this enemy
        // Each cycle consists of:
        // - T+1: attack with power 1 (T not multiple of 3)
        // - T+2: attack with power 1 (T not multiple of 3)
        // - T+3: attack with power 3 (T is multiple of 3)
        // Total damage per cycle: 5
        
        long long cycles = H[i] / 5;
        if (H[i] % 5 != 0) cycles++;
        
        T += cycles * 3;
    }
    
    cout << T << endl;
    return 0;
}