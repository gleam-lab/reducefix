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
            
            // Skip defeated enemies in front
            int j = i + 1;
            while (j < N && H[j] <= 0) j++;
            
            // If there are remaining enemies, we continue with the frontmost alive one
            if (j >= N) break;
            
            // The turn continues with the next enemy, so we need to simulate correctly
            // But according to problem, we always attack the frontmost enemy with health > 0
            // So if current enemy still has health, we keep attacking it
        }
    }
    
    cout << T << endl;
    return 0;
}