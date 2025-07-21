#include <iostream> // cin, cout
#include <string> // string
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    // Find the maximum and minimum positions of 'P', 'R', and 'S'
    int maxP = maxP = minP = maxR = minR = maxS = minS = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'P') {
            minP = min(minP, i);
            maxP = max(maxP, i);
        } else if (s[i] == 'R') {
            minR = min(minR, i);
            maxR = max(maxR, i);
        } else if (s[i] == 'S') {
            minS = min(minS, i);
            maxS = max(maxS, i);
        }
    }

    // Calculate the maximum possible wins by considering the positions of 'P', 'R', and 'S'
    int ans = max({maxP - minS, maxR - minP, maxS - minR});

    cout << ans << endl;
    return 0;
}