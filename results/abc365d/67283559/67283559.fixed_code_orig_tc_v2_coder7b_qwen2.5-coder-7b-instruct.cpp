#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> count(3, 0);
    for(char c : S) {
        if(c == 'R') count[0]++;
        else if(c == 'P') count[1]++;
        else count[2]++;
    }

    int result = 0;
    for(int i = 0; i < N; i++) {
        int max_score = 0;
        for(int j = 0; j < 3; j++) {
            int score = 0;
            if((S[i] == 'R' && j == 0) || (S[i] == 'P' && j == 1) || (S[i] == 'S' && j == 2)) {
                continue;
            }
            score += min(count[j], 1);
            count[j]--;
            if(S[i] == 'R') count[2]++;
            else if(S[i] == 'P') count[0]++;
            else count[1]++;
            max_score = max(max_score, score);
        }
        result += max_score;
        if(S[i] == 'R') count[0]++;
        else if(S[i] == 'P') count[1]++;
        else count[2]++;
    }

    cout << result << endl;

    return 0;
}