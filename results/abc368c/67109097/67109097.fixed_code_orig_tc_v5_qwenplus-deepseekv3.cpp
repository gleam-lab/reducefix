#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    
    long long T = 0;
    for (int i = 0; i < N; i++) {
        long long cycles = H[i] / 5;
        long long remainder = H[i] % 5;
        
        long long additional = 0;
        if (remainder > 0) {
            if (remainder <= 2) {
                additional = remainder;
            } else {
                additional = 3;
            }
        }
        
        T += cycles * 3 + additional;
        
        // Adjust for the attacks that might have been part of previous enemies' cycles
        // The next enemy's attacks start after T increments
    }
    cout << T << endl;
    return 0;
}