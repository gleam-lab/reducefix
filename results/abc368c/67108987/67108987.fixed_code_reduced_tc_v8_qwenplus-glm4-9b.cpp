#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    
    for (int i = 0; i < N; i++) {
        if (H[i] % 3 == 0) {
            T += H[i] / 3;
            H[i] = 0;
        } else {
            int k = 0;
            // Use the smallest multiple of 3 that is greater than or equal to H[i]
            while (H[i] - k >= 3) {
                k += 3;
            }
            T += (H[i] + k) / 3;
            H[i] -= k;
        }
    }
    
    cout << T << endl;
    return 0;
}