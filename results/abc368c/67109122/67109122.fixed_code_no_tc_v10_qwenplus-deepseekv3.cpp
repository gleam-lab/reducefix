#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    
    long long T = 0;
    for (int i = 0; i < N; i++) {
        long long full_cycles = H[i] / 5;
        long long remaining = H[i] % 5;
        
        if (remaining == 0) {
            T += full_cycles * 3;
            continue;
        }
        
        T += full_cycles * 3;
        long long temp_T = T;
        
        while (remaining > 0) {
            temp_T++;
            if (temp_T % 3 == 0) {
                remaining -= 3;
            } else {
                remaining -= 1;
            }
        }
        T = temp_T;
    }
    cout << T << endl;
    return 0;
}