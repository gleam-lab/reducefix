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
        while (H[i] > 0) {
            T++;
            if (T % 3 == 0) {
                H[i] -= 3;
            } else {
                H[i] -= 1;
            }
            // If current enemy is defeated, move to next enemy in the next iteration
            if (H[i] <= 0) break;
            
            // Skip enemies with health <= 0 at the front
            int j = i;
            while (j < N && H[j] <= 0) j++;
            if (j > i) {
                i = j - 1; // Will be incremented to j in the for loop
                break;
            }
        }
    }
    
    cout << T << endl;
    return 0;
}