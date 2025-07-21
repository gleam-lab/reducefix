#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    
    for (int i = 0; i < N; ++i) {
        if (H[i] % 3 == 0) {
            T += H[i] / 3;
        } else {
            int full Parts = H[i] / 3;
            T += full Parts * 3;
            T += 2;  // When H[i] is not divisible by 3, it will take 1 + 1 for the first two attacks, and another 3 for the third attack
            H[i] -= 6;  // After the above 3 attacks, health becomes 0
        }
    }
    
    cout << T << endl;
    return 0;
}