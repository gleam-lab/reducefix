#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) cin >> H[i];
    
    long long T = 0;
    for (int i = 0; i < N; ++i) {
        long long remaining = H[i];
        // Process in chunks where every 3 attacks deal 5 damage (1+1+3)
        long long chunks = remaining / 5;
        T += chunks * 3;
        remaining -= chunks * 5;
        
        // Process the remaining HP with individual attacks
        while (remaining > 0) {
            T++;
            if (T % 3 == 0) {
                remaining -= 3;
            } else {
                remaining -= 1;
            }
        }
    }
    cout << T << endl;
    return 0;
}