#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    
    ll T = 0;
    for (int i = 0; i < N; ++i) {
        ll cycles = H[i] / 5;
        ll remaining = H[i] % 5;
        
        T += cycles * 3;
        if (remaining > 0) {
            if (T % 3 == 0) {
                // Next attack (T+1) mod 3 is 1: damage 1
                if (remaining <= 1) {
                    T += 1;
                } else {
                    // T+1: damage 1 (remaining -=1)
                    // T+2: damage 1 (remaining -=1)
                    // T+3: damage 3 (remaining -=3)
                    if (remaining <= 2) {
                        T += 2;
                    } else {
                        T += 3;
                    }
                }
            } else if (T % 3 == 1) {
                // Next attack (T+1) mod 3 is 2: damage 1
                if (remaining <= 1) {
                    T += 1;
                } else {
                    // T+1: damage 1 (remaining -=1)
                    // T+2: damage 1 (remaining -=1)
                    // T+3: damage 3 (remaining -=3)
                    if (remaining <= 2) {
                        T += 1;
                    } else {
                        T += 2;
                    }
                }
            } else { // T % 3 == 2
                // Next attack (T+1) mod 3 is 0: damage 3
                if (remaining <= 3) {
                    T += 1;
                } else {
                    T += 2;
                }
            }
        }
    }
    cout << T << endl;
    return 0;
}