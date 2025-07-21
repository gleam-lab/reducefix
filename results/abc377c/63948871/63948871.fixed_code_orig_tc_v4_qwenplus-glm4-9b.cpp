bool is_in_bounds(i32 x, i32 y) {
    return x >= 1 && x <= N && y >= 1 && y <= N;
}

vector<pair<int, int>> get_capture_squares(i32 x, i32 y) {
    vector<pair<int, int>> captures = {
        {x + 2, y + 1}, {x + 1, y + 2}, {x - 1, y + 2},
        {x - 2, y + 1}, {x - 2, y - 1}, {x - 1, y - 2},
        {x + 1, y - 2}, {x + 2, y - 1}
    };
    captures.erase(remove_if(captures.begin(), captures.end(),
                              [](const pair<int, int>& p) { return !is_in_bounds(p.first, p.second); }),
                    captures.end());
    return captures;
}