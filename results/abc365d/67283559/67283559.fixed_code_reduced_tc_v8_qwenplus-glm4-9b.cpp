#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore(); // Ignore the newline character left in the input stream
    string S;
    getline(cin, S); // Use getline to read the whole line including spaces

    vector<char> hand = {'R', 'P', 'S'};
    int total = 0;

    // First pass: analyze the sequence from left to right
    for (int i = 0; i < N; ++i) {
        int score = 0;
        for (char option : hand) {
            if ((option == 'R' && S[i] == 'S') || 
                (option == 'P' && S[i] == 'R') || 
                (option == 'S' && S[i] == 'P')) {
                score++;
                break;
            }
        }
        total += score;
    }

    // Second pass: analyze the sequence from right to left
    int total2 = 0;
    string reversedS = S;
    reverse(reversedS.begin(), reversedS.end());
    for (int i = 0; i < N; ++i) {
        int score = 0;
        for (char option : hand) {
            if ((option == 'R' && reversedS[i] == 'S') || 
                (option == 'P' && reversedS[i] == 'R') || 
                (option == 'S' && reversedS[i] == 'P')) {
                score++;
                break;
            }
        }
        total2 += score;
    }

    cout << max(total, total2);
    return 0;
}