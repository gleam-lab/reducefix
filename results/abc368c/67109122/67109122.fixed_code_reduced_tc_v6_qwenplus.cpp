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
        // Process enemy i until its health drops to 0 or below
        while (H[i] > 0) {
            T++;
            if (T % 3 == 0) {
                H[i] -= 3;
            } else {
                H[i] -= 1;
            }
            // If this enemy is defeated, move to next
            if (H[i] <= 0) break;
            
            // Skip enemies with zero or negative health in the front
            int j = i + 1;
            while (j < N && H[j] <= 0) j++;
            if (j >= N) break;
            
            // Simulate passing turns without doing damage until we return to current cycle
            // But note: we always attack the first alive enemy, so we don't skip turns
            // The above while loop ensures we always attack the frontmost alive
        }
    }

    cout << T << endl;
    return 0;
}