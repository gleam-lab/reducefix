#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    vector<int> count(3); // count[0] for P, count[1] for R, count[2] for S
    int result = 0;

    for (char c : S) {
        int current = c - 'A'; // Convert character to index (0 for P, 1 for R, 2 for S)
        result += count[(current + 1) % 3]; // Add count of the next character in cycle
        count[current]++;
    }

    cout << result << endl;
    return 0;
}