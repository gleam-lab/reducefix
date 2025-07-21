#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> winCount(3, 0); // Counters for winning against R, P, and S respectively
    vector<int> loseCount(3, 0); // Counters for losing to R, P, and S respectively

    for(int i = 0; i < n; ++i) {
        char current = s[i];
        switch(current) {
            case 'R':
                loseCount[1]++; // Lose to paper
                loseCount[2]++; // Lose to scissors
                break;
            case 'P':
                loseCount[0]++; // Lose to rock
                loseCount[2]++; // Lose to scissors
                break;
            case 'S':
                loseCount[0]++; // Lose to rock
                loseCount[1]++; // Lose to paper
                break;
        }
    }

    // Calculate the maximum number of wins
    int maxWins = 0;
    for(int i = 0; i < 3; ++i) {
        maxWins += winCount[i];
    }

    cout << maxWins << endl;

    return 0;
}