#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    
    // Read enemy healths
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    
    long long T = 0;
    
    // Process each enemy
    for (int i = 0; i < N; ++i) {
        long long health = H[i];
        
        // If the health is divisible by 5, it can be attacked 5 times in sequence
        while (health >= 5) {
            health -= 5;
            T += 5;
        }
        
        // Process the remaining health which must be between 1 and 4
        if (health > 0) {
            switch (health) {
                case 1: // If health is 1, it takes one attack
                    T++;
                    break;
                case 2: // If health is 2, it takes two attacks
                    T += 2;
                    break;
                case 3: // If health is 3, it takes three attacks
                    T += 3;
                    break;
                case 4: // If health is 4, it takes three attacks
                    T += 3;
                    break;
            }
        }
    }
    
    cout << T << endl;
    
    return 0;
}