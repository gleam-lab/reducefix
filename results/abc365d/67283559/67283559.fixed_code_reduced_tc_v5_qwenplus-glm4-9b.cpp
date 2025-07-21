#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    vector<char> hand = {'R', 'P', 'S'};
    vector<char> next = hand;
    int total = 0;

    // First pass
    for (const auto& move : S) {
        char optimal = 'R';
        if (move == 'S') {
            optimal = 'R';
        } else if (move == 'R') {
            optimal = 'P';
        } else if (move == 'P') {
            optimal = 'S';
        }
        total += count(hand.begin(), hand.end(), optimal);
        hand = next;
    }

    // Reset for second pass
    next = hand;
    int total2 = 0;

    // Second pass
    for (const auto& move : S) {
        char optimal = 'R';
        if (move == 'S') {
            optimal = 'R';
        } else if (move == 'R') {
            optimal = 'P';
        } else if (move == 'P') {
            optimal = 'S';
        }
        total2 += count(hand.begin(), hand.end(), optimal);
        hand = next;
        next.clear();
        for (const auto& h : hand) {
            if (h != optimal) next.push_back(h);
        }
    }

    cout << max(total, total2);
    return 0;
}