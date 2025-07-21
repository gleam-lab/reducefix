#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    
    long long T = 0;
    long long pos = 0; // 0, 1, 2: indicates the position in the attack cycle (T mod 3)
    
    for (int i = 0; i < N; ++i) {
        long long h = H[i];
        long long full_cycles = h / 5;
        T += full_cycles * 3;
        h %= 5;
        
        if (h == 0) continue;
        
        // Determine the remaining attacks needed based on pos and remaining health
        if (pos == 0) {
            if (h <= 1) {
                T += 1;
                pos = 1;
            } else if (h <= 2) {
                T += 2;
                pos = 2;
            } else {
                T += 3;
                pos = 0;
            }
        } else if (pos == 1) {
            if (h <= 1) {
                T += 1;
                pos = 2;
            } else if (h <= 3) {
                T += 2;
                pos = 0;
            } else {
                T += 3;
                pos = 1;
            }
        } else if (pos == 2) {
            if (h <= 3) {
                T += 1;
                pos = 0;
            } else {
                T += 2;
                pos = 1;
            }
        }
    }
    
    cout << T << endl;
    
    return 0;
}