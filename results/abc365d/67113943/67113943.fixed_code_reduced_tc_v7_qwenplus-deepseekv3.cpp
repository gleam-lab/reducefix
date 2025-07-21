#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;
    int wins = 0;
    for (int i = 0; i < N; ) {
        char current = S[i];
        int j = i;
        while (j < N && S[j] == current) {
            j++;
        }
        if (current == 'R') {
            wins += j - i;
        } else if (current == 'P') {
            wins += j - i;
        } else if (current == 'S') {
            wins += j - i;
        }
        i = j;
    }
    cout << wins;
}