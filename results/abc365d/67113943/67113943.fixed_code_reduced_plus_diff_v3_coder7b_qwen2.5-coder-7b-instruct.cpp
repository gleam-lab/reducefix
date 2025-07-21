#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;

    int wins = 0;
    unordered_map<char, char> moves = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    char prevMove = 'A'; // Initialize with a move that won't be in the sequence

    for (char c : S) {
        if (moves[prevMove] == c) {
            wins++;
        }
        prevMove = c;
    }

    cout << wins << endl;
    return 0;
}