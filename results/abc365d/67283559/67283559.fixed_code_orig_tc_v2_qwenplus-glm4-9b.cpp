#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S = S.substr(0, N); // Read the string and limit it to N characters
    vector<char> hand = {'R', 'P', 'S'};
    int total = 0;

    // First pass: Calculate the score for choosing the best response
    vector<char> next(hand.size());
    for (int i = 0; i < hand.size(); ++i) {
        next[i] = hand[i] == 'R' ? 'S' : hand[i] == 'S' ? 'R' : 'P';
    }

    for (int i = 0; i < S.length(); ++i) {
        int score = 0;
        char use = next[S[i] - 'R'];
        if (use == 'R' && S[i] == 'S') {
            score++;
        } else if (use == 'P' && S[i] == 'R') {
            score++;
        } else if (use == 'S' && S[i] == 'P') {
            score++;
        }
        if (score == 0) {
            use = S[i];
        }
        total += score;
        next[S[i] - 'R'] = use;
    }

    // Second pass: Calculate the score for the initial strategy
    vector<char> next2(hand.size());
    for (int i = 0; i < hand.size(); ++i) {
        next2[i] = hand[i] == 'R' ? 'S' : hand[i] == 'S' ? 'R' : 'P';
    }
    next2[S[0] - 'R'] = S[0];

    for (int i = 1; i < S.length(); ++i) {
        int score = 0;
        char use = next2[S[i] - 'R'];
        if (use == 'R' && S[i] == 'S') {
            score++;
        } else if (use == 'P' && S[i] == 'R') {
            score++;
        } else if (use == 'S' && S[i] == 'P') {
            score++;
        }
        if (score == 0) {
            use = S[i];
        }
        next2[S[i] - 'R'] = use;
    }
    int total2 = 0;
    for (int i = 0; i < S.length(); ++i) {
        total2 += next2[S[i] - 'R'] == S[i];
    }

    // Compare and output the maximum score from the two strategies
    cout << max(total, total2) << endl;
}