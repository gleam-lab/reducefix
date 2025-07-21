#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<char> hand = {'R', 'P', 'S'};
    int total = 0;

    // Calculate the total score in the first pass
    for (int i = 0; i < N; i++) {
        int score = 0;
        for (char &c : hand) {
            if ((c == 'R' && S[i] == 'S') ||
                (c == 'P' && S[i] == 'R') ||
                (c == 'S' && S[i] == 'P')) {
                score++;
                hand.erase(remove(hand.begin(), hand.end(), c), hand.end());
                break;
            }
        }
        total += score;
    }

    // Calculate the total score in the second pass
    hand = {'R', 'P', 'S'}; // Reset the hand for second pass
    int total2 = 0;

    for (int i = 1; i < N; i++) {
        int score = 0;
        for (char &c : hand) {
            if ((c == 'R' && S[i] == 'S') ||
                (c == 'P' && S[i] == 'R') ||
                (c == 'S' && S[i] == 'P')) {
                score++;
                hand.erase(remove(hand.begin(), hand.end(), c), hand.end());
                break;
            }
        }
        total2 += score;
    }

    cout << max(total, total2);
    return 0;
}