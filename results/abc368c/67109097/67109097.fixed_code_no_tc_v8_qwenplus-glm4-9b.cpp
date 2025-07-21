#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    
    for (int i = 0; i < N; i++) {
        if (H[i] <= 0) continue; // Skip enemies with 0 or less health
        if (H[i] % 3 == 0) {
            // If health is a multiple of 3, decrease health by 3 until it's no longer a multiple of 3
            while (H[i] % 3 == 0) {
                H[i] /= 3;
                T += 3;
            }
        }
        // Now health is not a multiple of 3, decrease it until it is or until it reaches 0
        while (H[i] > 0) {
            if (H[i] == 1) {
                T++;
                H[i] = 0;
                break;
            } else if (H[i] % 3 == 1) {
                T += 2; // Decrease by 1 and then by 1 more
                H[i] -= 2;
            } else {
                T += 3; // Decrease by 3
                H[i] -= 3;
            }
        }
    }
    
    cout << T << endl;
    return 0;
}