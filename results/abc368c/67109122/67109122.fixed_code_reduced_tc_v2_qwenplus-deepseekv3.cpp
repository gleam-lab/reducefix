#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    
    long long T = 0;
    for (int i = 0; i < N; i++) {
        long long cycles = H[i] / 5;
        long long remaining = H[i] % 5;
        
        T += cycles * 3;
        if (remaining > 0) {
            if (remaining <= 2) {
                T += remaining;
            } else {
                T += 3;
            }
        }
    }
    
    cout << T << endl;
    return 0;
}