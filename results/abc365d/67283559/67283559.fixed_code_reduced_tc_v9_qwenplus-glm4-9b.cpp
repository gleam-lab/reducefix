#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<char> hand = {'R', 'P', 'S'};
    int total = 0;

    for (int i = 0; i < N; i++) {
        int score = 0;
        vector<char> next(hand);
        char use;
        for (char d : next) {
            char n = d;
            if (n == 'R' && S[i] == 'S') {
                score++;
                use = 'R';
                break;
            }
            if (n == 'P' && S[i] == 'R') {
                score++;
                use = 'P';
                break;
            }
            if (n == 'S' && S[i] == 'P') {
                score++;
                use = 'S';
                break;
            }
        }
        if (score == 0) use = S[i];
        for (auto &d : next) if (d == use) d = 0; // Mark used to avoid reusing the same character
        total += score;
    }
    
    int total2 = total; // Reset total for the second calculation
    for (int i = 0; i < N; i++) {
        int score = 0;
        vector<char> next(hand);
        char use;
        for (char d : next) {
            char n = d;
            if (n == 'R' && S[i] == 'S') {
                score++;
                use = 'R';
                break;
            }
            if (n == 'P' && S[i] == 'R') {
                score++;
                use = 'P';
                break;
            }
            if (n == 'S' && S[i] == 'P') {
                score++;
                use = 'S';
                break;
            }
        }
        if (score == 0) use = S[i];
        for (auto &d : next) if (d == use) d = 0; // Mark used to avoid reusing the same character
        total2 += score;
    }
    
    cout << max(total, total2);
    return 0;
}