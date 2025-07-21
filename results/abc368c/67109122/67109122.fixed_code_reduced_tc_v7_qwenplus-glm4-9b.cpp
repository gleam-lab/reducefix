#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;

    for (int i = 0; i < N; i++) {
        // Calculate how many full 3's can be subtracted
        T += (H[i] + 2) / 3;
        // Subtract health in increments of 3 if possible
        H[i] -= (H[i] + 2) / 3 * 3;
    }

    // Subtract remaining health
    for (int i = 0; i < N; i++) {
        T += H[i];
    }

    cout << T << endl;
    return 0;
}