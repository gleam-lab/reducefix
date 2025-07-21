#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    
    for (int i = 0; i < N; i++) {
        long long decrement = H[i] / 3; // Instead of /5, we consider the multiples of 3 separately
        H[i] -= decrement * 3;
        T += decrement * 3; // Add decrement * 3 to T
        
        // If there's any health remaining after decrementing with multiples of 3
        if (H[i] > 0) {
            T += 1; // Attack once more to decrease the remaining health
            H[i] -= 1; // Decrease health by 1 (or 3 when T is a multiple of 3 which is handled above)
        }
    }
    
    cout << T << endl;
    return 0;
}