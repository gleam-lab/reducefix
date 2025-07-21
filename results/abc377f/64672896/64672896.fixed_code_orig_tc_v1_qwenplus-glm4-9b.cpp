#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    // Sets to store the indices of under-attack rows, columns, and diagonals
    unordered_set<int> under_attack_rows, under_attack_cols;
    unordered_set<pair<int, int>, pair<hash<int>, hash<int>>> under_attack_diag1, under_attack_diag2;
    
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        
        // Add the row and column to the respective sets
        under_attack_rows.insert(a);
        under_attack_cols.insert(b);
        
        // Add the diagonals to the respective sets
        under_attack_diag1.insert({a + b, 0});
        under_attack_diag2.insert({a - b, 0});
    }
    
    // Counter for under-attack rows, columns, and diagonals
    int under_attack_row_count = 0, under_attack_col_count = 0;
    int under_attack_diag1_count = 0, under_attack_diag2_count = 0;
    
    // Count how many rows, columns, and diagonals are under attack
    for (int i = 1; i <= N; ++i) {
        if (under_attack_rows.count(i)) under_attack_row_count++;
        if (under_attack_cols.count(i)) under_attack_col_count++;
        
        // Count the number of squares on the diagonals (i + j) and (i - j)
        int diag1 = i + 1, diag2 = i - 1;
        while (diag1 <= N) {
            if (under_attack_diag1.count({diag1, 0})) under_attack_diag1_count++;
            if (under_attack_diag2.count({diag2, 0})) under_attack_diag2_count++;
            diag1++;
            diag2--;
        }
    }
    
    // Calculate the number of safe squares
    int total_squares = N * N;
    int safe_squares = total_squares - (under_attack_row_count + under_attack_col_count + under_attack_diag1_count + under_attack_diag2_count / 2);
    
    cout << safe_squares << endl;
    
    return 0;
}