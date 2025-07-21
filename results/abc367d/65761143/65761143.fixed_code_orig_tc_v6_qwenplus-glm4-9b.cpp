#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);

    int sum = 0;
    for (int &x : a) {
        cin >> x;
        x -= x / m * m; // More efficient modulo operation
        sum = (sum + x) % m;
    }

    int res = 0;
    unordered_map<int, int> count;
    count[0]++;
    
    for (int x : a) {
        count[sum]++;
        int complement = (m - (sum - x) % m) % m; // Calculate complement
        count[complement]++;
        if (count[complement] == 2) {
            count[complement]--; // Avoid counting twice
            res++; // Found a valid pair
        }
        sum = (sum + x) % m;
    }

    cout << res << '\n';
    return 0;
}