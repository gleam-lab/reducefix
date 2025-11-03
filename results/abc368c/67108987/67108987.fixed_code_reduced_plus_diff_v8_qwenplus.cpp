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
            if (H[i] <= 0) break;
            
            // If we still have damage to deal but current enemy is not frontmost,
            // we need to defeat all previous enemies first, but in this simulation
            // we process enemies sequentially, so we just continue attacking current
        }
    }
    
    cout << T << endl;
    return 0;
}