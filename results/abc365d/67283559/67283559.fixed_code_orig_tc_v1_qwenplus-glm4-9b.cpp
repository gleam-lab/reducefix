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

    for (int i = 0; i < N; ++i) {
        int score = 0;
        char use;
        for (char d : hand) {
            if ((d == 'R' && S[i] == 'S') || (d == 'P' && S[i] == 'R') || (d == 'S' && S[i] == 'P')) {
                score++;
                use = d;
                break;
            }
        }
        total += score;
    }

    cout << total << endl;
    return 0;
}