#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    set<long long> x, y, x2, y2;
    long long a, b;

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a; --b; // Convert 1-based index to 0-based index
        // Add the position of the piece
        x.insert(a);
        y.insert(b);
        // Add the positions that can potentially capture the piece
        x2.insert(a + 1);
        x2.insert(a - 1);
        x2.insert(a + 2);
        x2.insert(a - 2);
        y2.insert(b + 1);
        y2.insert(b - 1);
        y2.insert(b + 2);
        y2.insert(b - 2);
    }

    // Calculate the safe cells
    long long safe_x = n - x.size() - x2.size();
    long long safe_y = n - y.size() - y2.size();
    long long safe = safe_x * safe_y;

    cout << safe << endl;

    return 0;
}