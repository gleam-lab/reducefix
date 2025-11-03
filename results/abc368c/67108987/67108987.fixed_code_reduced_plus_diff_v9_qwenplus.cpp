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
        // Process enemy i until its health becomes <= 0
        while (H[i] > 0) {
            T++;
            if (T % 3 == 0) {
                H[i] -= 3;
            } else {
                H[i] -= 1;
            }
            
            // If this enemy is defeated, move to next
            if (H[i] <= 0) {
                break;
            }
            
            // If there are remaining enemies, we need to process them first
            // But according to problem, we always attack frontmost enemy with health > 0
            // So we stay on current enemy until it's defeated
        }
    }
    
    cout << T << endl;
    return 0;
}