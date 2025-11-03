#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long T = 0;
    int pos = 0; // Position in the cycle: 0,1 -> -1 damage, 2 -> -3 damage

    for (int i = 0; i < N; ++i) {
        long long health = H[i];
        
        // Process current enemy
        while (health > 0) {
            T++;
            pos = (pos + 1) % 3;
            
            if (pos == 0) { // Every 3rd attack deals 3 damage
                health -= 3;
            } else {
                health -= 1;
            }
        }
    }

    cout << T << endl;
    return 0;
}