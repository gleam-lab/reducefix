#include <iostream>
#include <map>
#include <string>
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
    int total = 0;
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == s[i-1] || beats[s[i-1]] == s[i]) {
            total++;
        }
    }
    cout << total + 1 << endl; // Adding the first move to the count

    return 0;
}