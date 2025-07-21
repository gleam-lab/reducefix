#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Initialize result with the number of games Takahashi can win if he plays optimally
    int result = n;

    // Iterate through each move
    for(int i = 0; i < n; ++i) {
        char move = s[i];

        // If the move is 'P', Takahashi should play 'S' to win or avoid losing
        if(move == 'P') {
            result++;
        }
        // If the move is 'R', Takahashi should play 'P' to win or avoid losing
        else if(move == 'R') {
            result++;
        }
        // If the move is 'S', Takahashi should play 'R' to win or avoid losing
        else {
            result++;
        }
    }

    // Print the result
    cout << result / 2 << endl;

    return 0;
}