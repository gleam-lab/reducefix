#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    
    long long T = 0;
    for (int i = 0; i < N; ++i) {
        long long h = H[i];
        if (h <= 0) continue;
        
        // The damage pattern is: 1, 1, 3, 1, 1, 3, ...
        // So every 3 steps, the total damage is 5 (1+1+3)
        long long full_cycles = h / 5;
        long long remaining = h % 5;
        
        T += full_cycles * 3;
        h -= full_cycles * 5;
        
        if (h > 0) {
            if (h <= 1) {
                T += 1;
            } else if (h <= 2) {
                T += 2;
            } else { // h <= 4
                T += 3;
            }
        }
    }
    
    cout << T << endl;
    return 0;
}