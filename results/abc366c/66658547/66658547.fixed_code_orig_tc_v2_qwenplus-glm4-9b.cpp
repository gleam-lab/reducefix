#include <iostream>
#include <set>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    
    set<int> balls; // Using a set to store unique ball numbers
    
    for (int i = 0; i < Q; ++i) {
        int queryType;
        cin >> queryType;
        
        if (queryType == 1) {
            int ballNumber;
            cin >> ballNumber;
            balls.insert(ballNumber); // Insert new ball into the set
        } else if (queryType == 2) {
            int ballNumber;
            cin >> ballNumber;
            balls.erase(ballNumber); // Remove ball from the set
        } else if (queryType == 3) {
            cout << balls.size() << "\n"; // Output the number of unique balls
        }
    }
    
    return 0;
}