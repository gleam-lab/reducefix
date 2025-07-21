#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    
    int ans = 0;
    char last_move = 'N'; // Initialize with a dummy value
    
    for (char c : S) {
        if (c == 'P') {
            if (last_move != 'S') {
                ans++; // Win against Scissors
                last_move = 'S';
            } else {
                last_move = 'P'; // Draw with Paper
            }
        } else if (c == 'R') {
            if (last_move != 'P') {
                ans++; // Win against Paper
                last_move = 'P';
            } else {
                last_move = 'R'; // Draw with Rock
            }
        } else { // c == 'S'
            if (last_move != 'R') {
                ans++; // Win against Rock
                last_move = 'R';
            } else {
                last_move = 'S'; // Draw with Scissors
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}