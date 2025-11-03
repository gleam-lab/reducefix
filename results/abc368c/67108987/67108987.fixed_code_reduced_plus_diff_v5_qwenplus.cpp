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
        // Process each enemy
        while (H[i] > 0) {
            T++;
            if (T % 3 == 0) {
                H[i] -= 3;
            } else {
                H[i] -= 1;
            }
            
            // If current enemy is defeated, move to next
            if (H[i] <= 0) break;
            
            // Check if any previous enemy still has health
            bool need_to_go_back = false;
            for (int j = 0; j < i; j++) {
                if (H[j] > 0) {
                    need_to_go_back = true;
                    break;
                }
            }
            
            if (need_to_go_back) {
                // We need to go back and fight previous enemies
                // Reset to first enemy with positive health
                int next_i = 0;
                while (next_i < N && H[next_i] <= 0) next_i++;
                if (next_i < N) {
                    i = next_i - 1; // will be incremented to next_i in the loop
                }
                break;
            }
        }
    }
    
    cout << T << endl;
    return 0;
}