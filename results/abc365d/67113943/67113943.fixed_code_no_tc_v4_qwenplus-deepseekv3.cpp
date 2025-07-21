#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;
    
    int R_count = count(S.begin(), S.end(), 'R');
    int P_count = count(S.begin(), S.end(), 'P');
    int S_count = count(S.begin(), S.end(), 'S');
    
    int max_wins = 0;
    if (R_count > 0) max_wins += P_count;
    if (P_count > 0) max_wins += S_count;
    if (S_count > 0) max_wins += R_count;
    
    cout << max_wins << endl;
    
    return 0;
}