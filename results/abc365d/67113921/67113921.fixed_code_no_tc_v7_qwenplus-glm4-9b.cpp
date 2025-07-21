#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;

    int wins = 0;
    char winmove[3] = {'R', 'P', 'S'};
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'R') {
            if (S[i+1] == 'P') wins++;
        } else if (S[i] == 'P') {
            if (S[i+1] == 'R') wins++;
        } else if (S[i] == 'S') {
            if (S[i+1] == 'P') wins++;
        }
        if (i < N - 1) i++; // Skip the next character since we already checked it
    }
    
    cout << wins;
}