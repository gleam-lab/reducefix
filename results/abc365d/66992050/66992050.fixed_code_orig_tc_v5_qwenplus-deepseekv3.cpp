#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    
    int ans = 0;
    char last = '\0';
    
    for (int i = 0; i < N; ) {
        char current = S[i];
        char best_move;
        if (current == 'P') best_move = 'S';
        else if (current == 'R') best_move = 'P';
        else best_move = 'R';
        
        int j = i;
        while (j < N && S[j] == current) {
            j++;
        }
        
        if (best_move != last) {
            ans += j - i;
            last = best_move;
        } else {
            last = '\0';
        }
        
        i = j;
    }
    
    cout << ans << endl;
    return 0;
}