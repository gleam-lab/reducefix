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
        // Process enemy i
        while (H[i] > 0) {
            T++;
            if (T % 3 == 0) {
                H[i] -= 3;
            } else {
                H[i] -= 1;
            }
            
            // If this enemy is defeated, move to next
            if (H[i] <= 0) break;
            
            // Skip all subsequent enemies with health 0 or less
            int j = i + 1;
            while (j < N && H[j] <= 0) j++;
            
            // If there are more enemies, we would attack the frontmost one,
            // but since we're simulating per-enemy, we just continue
            // attacking current enemy until it's dead
        }
    }
    
    cout << T << endl;
    return 0;
}