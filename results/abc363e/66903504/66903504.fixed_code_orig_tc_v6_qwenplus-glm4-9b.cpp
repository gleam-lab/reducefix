// Initialize variables
int H, W, Y;
cin >> H >> W >> Y;
vector<vector<int>> A(H, vector<int>(W));
// Read the elevation matrix

vector<vector<bool>> visited(H, vector<bool>(W, false));

// Initialize the set with the edges of the grid
set<pair<int, int>> sinking_set;
for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
        if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
            sinking_set.insert({A[i][j], i * W + j});
        }
    }
}

int remaining_area = H * W;

// Process year by year
for (int year = 0; year < Y; ++year) {
    set<pair<int, int>> new_sinking_set;
    for (auto& p : sinking_set) {
        int elevation = p.first;
        int index = p.second;

        // Check adjacent cells and mark them if they can sink
        // ...

        // Update the remaining area
        remaining_area -= 1;  // Subtract the current sinking cell

        // If adjacent cells are marked, they will be processed in the next year
        new_sinking_set.insert({elevation, index});
    }

    sinking_set = new_sinking_set;
    cout << remaining_area << endl;
}