#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;
    
    int wins = 0;
    for (char c : S) {
        if (c == 'R') {
            wins += (c == 'R') ? 1 : 0;
        } else if (c == 'P') {
            wins += (c == 'P') ? 1 : 0;
        } else if (c == 'S') {
            wins += (c == 'S') ? 1 : 0;
        }
    }
    
    // Now, we need to count the optimal wins by always choosing the best move
    wins = 0;
    for (char c : S) {
        if (c == 'R') {
            wins++; // P beats R
        } else if (c == 'P') {
            wins++; // S beats P
        } else if (c == 'S') {
            wins++; // R beats S
        }
    }
    
    cout << wins << "\n";
    return 0;
}