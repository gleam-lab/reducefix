#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N + 1); // Changed size to N+1 for zero-based indexing convenience
    for (int i = 1; i <= N; i++) cin >> H[i];

    long long T = 0;
    for (int i = 1; i <= N; ) { // Loop through each enemy only once
        if (H[i] > 0) {
            T++;
            H[i]--;
            if (T % 3 == 0) {
                T++; // For every 3rd attack, increase T by one
                H[i] -= 3;
            } else {
                H[i]--; // Decrease health by 1 otherwise
            }
        } else {
            i++; // Move to next enemy if current is already defeated
        }
    }

    cout << T << endl;
    return 0;
}