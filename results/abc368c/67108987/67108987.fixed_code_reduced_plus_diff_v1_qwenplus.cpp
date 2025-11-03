#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    
    long long T = 0;
    for (int i = 0; i < N; i++) {
        // Process each enemy one by one
        while (H[i] > 0) {
            T++;
            if (T % 3 == 0) {
                H[i] -= 3;
            } else {
                H[i] -= 1;
            }
            
            // If current enemy is defeated, move to next
            if (H[i] <= 0) {
                break;
            }
            
            // If there are remaining enemies, the attack will continue to them
            // But we need to simulate properly - we always attack the first non-zero enemy
            // So after attacking current, if it's still alive, we stay on it
            // Otherwise, we move to next in the loop
        }
    }
    
    cout << T << endl;
    return 0;
}