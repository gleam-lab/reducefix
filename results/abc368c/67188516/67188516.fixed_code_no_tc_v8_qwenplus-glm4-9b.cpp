#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    long long T = 0;
    
    // Read enemy healths
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
        T += H[i] / 3;  // Add full 3 damage hits as they do not affect the parity of remaining health
        if (H[i] % 3 == 2) {
            T += 2;  // Two 1 damage hits are needed to bring health to 0 if remainder is 2
        } else if (H[i] % 3 == 1) {
            T += 1;  // One 1 damage hit is needed to bring health to 0 if remainder is 1
        }
    }
    
    cout << T << endl;
    return 0;
}