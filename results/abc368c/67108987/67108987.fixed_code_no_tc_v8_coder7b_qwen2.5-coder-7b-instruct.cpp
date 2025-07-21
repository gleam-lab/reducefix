#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N + 1); // Adjusted to use 1-based index for simplicity
    for (int i = 1; i <= N; i++) cin >> H[i];
    long long T = 0;
    while(true) {
        bool any_alive = false; // Flag to check if any enemy is still alive
        for (int i = 1; i <= N; i++) {
            if (H[i] > 0) {
                any_alive = true;
                if ((T % 3) == 0) H[i] -= 3;
                else H[i] -= 1;
                T++;
                if (H[i] < 0) H[i] = 0; // Ensure health does not go below zero
            }
        }
        if (!any_alive) break; // Exit loop if no enemies are left
    }
    cout << T << endl;
    return 0;
}