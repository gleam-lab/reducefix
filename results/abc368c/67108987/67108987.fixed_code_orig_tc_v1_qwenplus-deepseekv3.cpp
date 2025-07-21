#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N + 1);
    for (int i = 1; i <= N; i++) cin >> H[i];
    long long T = 0;
    for (int i = 1; i <= N; i++) {
        long long full_cycles = H[i] / 5;
        T += full_cycles * 3;
        H[i] -= full_cycles * 5;
        
        while (H[i] > 0) {
            T++;
            if (T % 3 == 0) {
                H[i] -= 3;
            } else {
                H[i] -= 1;
            }
        }
    }
    cout << T << endl;
    return 0;
}