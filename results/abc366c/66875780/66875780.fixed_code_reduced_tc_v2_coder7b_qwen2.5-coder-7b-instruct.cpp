#include <iostream>
#include <set>

using namespace std;

// Fast IO
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// Function to handle each query
void processQueries(int Q)
{
    set<int> s; // Set to store unique numbers
    for (int q = 0; q < Q; ++q)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x;
            cin >> x;
            s.insert(x); // Insert element into set
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            s.erase(s.find(x)); // Erase element from set
        }
        else if (type == 3)
        {
            cout << s.size() << '\n'; // Output size of set
        }
    }
}

int main()
{
    fastIO();
    int Q;
    cin >> Q;
    processQueries(Q);
    return 0;
}