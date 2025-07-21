#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N + 1);
    for (int i = 1; i <= N; i++) cin >> H[i];
    long long T = 0;
    for (int i = 1; i <= N; i++) {
        if (H[i] > 0) {
            long long attacks = (H[i] + 2) / 3; // Calculate minimum number of attacks needed
            T += 3 * attacks; // Each attack costs 3 steps if T is a multiple of 3
            H[i] -= 3 * attacks;
            if (H[i] > 0) { // If health is still positive after 3 attacks, perform one more attack
                T += 1;
                H[i]--;
            }
        }
    }
    cout << T << endl;
    return 0;
}