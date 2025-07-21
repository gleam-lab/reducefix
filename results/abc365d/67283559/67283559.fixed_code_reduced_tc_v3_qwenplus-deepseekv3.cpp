#include <bits/stdc++.h>
using namespace std;

int calculateMaxWins(const string& S, char initialChoice) {
    int total = 0;
    char prev = initialChoice;
    if (prev == 'R' && S[0] == 'S') total++;
    else if (prev == 'P' && S[0] == 'R') total++;
    else if (prev == 'S' && S[0] == 'P') total++;

    for (size_t i = 1; i < S.size(); ++i) {
        char current;
        if (prev != 'R' && prev != 'P') {
            // Previous was 'S', choose between 'R' and 'P'
            if ('R' == S[i]) current = 'P';
            else if ('P' == S[i]) current = 'R';
            else current = (rand() % 2 == 0) ? 'R' : 'P';
        } else if (prev != 'P' && prev != 'S') {
            // Previous was 'R', choose between 'P' and 'S'
            if ('P' == S[i]) current = 'S';
            else if ('S' == S[i]) current = 'P';
            else current = (rand() % 2 == 0) ? 'P' : 'S';
        } else {
            // Previous was 'P', choose between 'R' and 'S'
            if ('R' == S[i]) current = 'S';
            else if ('S' == S[i]) current = 'R';
            else current = (rand() % 2 == 0) ? 'R' : 'S';
        }

        // Determine if current choice wins
        if (current == 'R' && S[i] == 'S') total++;
        else if (current == 'P' && S[i] == 'R') total++;
        else if (current == 'S' && S[i] == 'P') total++;

        prev = current;
    }
    return total;
}

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }

    // Determine possible initial choices (not S[0])
    vector<char> initialChoices;
    if (S[0] != 'R') initialChoices.push_back('R');
    if (S[0] != 'P') initialChoices.push_back('P');
    if (S[0] != 'S') initialChoices.push_back('S');

    int maxWins = 0;
    for (char choice : initialChoices) {
        int wins = calculateMaxWins(S, choice);
        if (wins > maxWins) {
            maxWins = wins;
        }
    }

    cout << maxWins << endl;
    return 0;
}