#include <iostream>
#include <map>
using namespace std;
#define endl '\n'
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;

    int total = 0; // Reset total to 0 for correct counting
    char last_move = beats[s[0]]; // Initialize with the beat of the first character
    char current_move = s[0]; // Initialize with the first move

    for (int i = 1; i < n; i++) {
        current_move = s[i]; // Update the current move
        if (beats[current_move] == last_move || beats[current_move] == current_move) {
            // If the current move is the same as the last or beats the previous move, do not increment
            continue;
        }
        last_move = current_move;
        total++; // Increment total only if the current move neither follows nor beats the previous one
    }

    cout << total << endl;

    return 0;
}