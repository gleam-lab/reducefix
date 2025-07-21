#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    char past = 'N'; // Initialize past character to 'N' (not used)
    int ans = 0; // Initialize answer counter to 0

    for (char c : S) {
        if (c == 'P') {
            if (!(past == 'S')) { // If the previous character was not 'S'
                ans++; // Increment the answer counter
                past = 'S'; // Update the past character to 'S'
            } else {
                past = 'P'; // Update the past character to 'P'
            }
        }
        if (c == 'R') {
            if (!(past == 'P')) { // If the previous character was not 'P'
                ans++; // Increment the answer counter
                past = 'P'; // Update the past character to 'P'
            } else {
                past = 'R'; // Update the past character to 'R'
            }
        }
        if (c == 'S') {
            if (!(past == 'R')) { // If the previous character was not 'R'
                ans++; // Increment the answer counter
                past = 'R'; // Update the past character to 'R'
            } else {
                past = 'S'; // Update the past character to 'S'
            }
        }
    }

    cout << ans; // Output the final answer
    return 0;
}