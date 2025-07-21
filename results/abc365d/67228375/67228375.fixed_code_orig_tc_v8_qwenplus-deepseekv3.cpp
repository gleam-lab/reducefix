#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;

    int dpR = 0, dpP = 0, dpS = 0;
    for (char c : s) {
        int newR = dpR, newP = dpP, newS = dpS;
        if (beats[c] == 'R') {
            newR = max(dpR, max(dpP, dpS)) + 1;
        } else if (beats[c] == 'P') {
            newP = max(dpR, max(dpP, dpS)) + 1;
        } else if (beats[c] == 'S') {
            newS = max(dpR, max(dpP, dpS)) + 1;
        }
        dpR = newR;
        dpP = newP;
        dpS = newS;
    }

    cout << max(dpR, max(dpP, dpS)) << endl;

    return 0;
}