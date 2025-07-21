#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    set<pair<long long, long long>> occupied;
    set<pair<long long, long long>> attackable;
    pair<long long, long long> p;

    // Read the positions of the pieces already on the board and add them to the occupied set
    for (int i = 0; i < M; i++) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        // Determine the attackable positions based on the piece's movement rules
        for (int j = 0; j < 8; j++) {
            long long x = a + (j % 2) * 2 - (j / 2);
            long long y = b + (j < 4) * 2 - (j > 3) * 2;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attackable.insert({x, y});
            }
        }
    }

    // Calculate the total number of attackable positions
    long long attackable_count = attackable.size();

    // Iterate through all positions on the board
    for (long long i = 1; i <= N; i++) {
        for (long long j = 1; j <= N; j++) {
            // Check if the position is not occupied and not attackable
            if (occupied.find({i, j}) == occupied.end() && attackable.find({i, j}) == attackable.end()) {
                // The position is safe for placing a new piece
                cout << "1";
            } else {
                // The position is either occupied or attackable
                cout << "0";
            }
            cout << (j < N ? " " : "\n");
        }
    }

    return 0;
}