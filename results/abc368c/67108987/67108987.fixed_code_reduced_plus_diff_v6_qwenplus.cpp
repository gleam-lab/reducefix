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
            
            // If current enemy is defeated, move to next
            if (H[i] <= 0) break;
            
            // Skip defeated enemies at the front
            while (i + 1 < N && H[i + 1] <= 0) {
                i++;
            }
        }
    }
    
    cout << T << endl;
    return 0;
}