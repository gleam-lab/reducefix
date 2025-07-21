#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long T = 0;

    for (int i = 0; i < N; ++i) {
        int health;
        cin >> health;
        
        // Calculate full 3's damage
        T += health / 3;
        
        // Calculate remainder health that can be taken care of by non-multiple of 3 damage
        int remainder = health % 3;
        
        // Adjust T to account for the remainder
        if (remainder == 1) {
            // We need one more attack that does not make T a multiple of 3
            // We can handle this by reducing the number of full 3's damage
            // or by adding an extra attack
            T -= 1; // Reduce one 3's damage
        } else if (remainder == 2) {
            // We need two more attacks that do not make T a multiple of 3
            // We can handle this by reducing the number of full 3's damage
            // or by adding two extra attacks
            T -= 2; // Reduce two 3's damage
        }
    }
    
    cout << T << endl;
    return 0;
}