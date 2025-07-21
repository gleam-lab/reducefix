#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Constants
const int INF = 1e9 + 7;

// Fast IO
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// Main function
int main()
{
    fastIO();

    int Q;
    cin >> Q;
    set<int> s;

    while (Q--) {
        int a;
        cin >> a;

        if (a == 1) {
            int tp;
            cin >> tp;
            s.insert(tp);
        } else if (a == 2) {
            int tp;
            cin >> tp;
            s.erase(s.find(tp));
        } else {
            cout << s.size() << "\n";
        }
    }

    return 0;
}