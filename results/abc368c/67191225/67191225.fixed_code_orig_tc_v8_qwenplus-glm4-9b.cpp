#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    
    long long T = 0;
    
    while (true) {
        int i = 0;
        bool allDefeated = true;
        
        while (i < N) {
            if (H[i] == 0) {
                i++;
                continue;
            }
            
            if (T % 3 == 0) {
                // Attack deals 3 damage
                if (H[i] > 3) {
                    H[i] -= 3;
                } else {
                    H[i] = 0;
                }
            } else {
                // Attack deals 1 damage
                if (H[i] > 1) {
                    H[i]--;
                } else {
                    H[i] = 0;
                    if (H[i] == 0 && T % 5 == 1) {
                        // If this is the last enemy and T is 1 mod 5, we need to adjust T to make next attack a multiple of 3
                        T++;
                        break;
                    }
                }
            }
            
            i++;
            allDefeated = false;
        }
        
        if (allDefeated) {
            break;
        }
        
        T++;
    }
    
    cout << T << endl;
    return 0;
}