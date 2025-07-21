// ...

int main() {
    // ...
    rep3( i, 1, W-1 ) {
        pq.push( { A[0][i], 0, i } );
        used[0][i] = 1;
    }
    rep3( i, 1, H-1 ) {
        pq.push( { A[i][0], i, 0 } );
        used[i][0] = 1;
    }
    rep3( i, 1, H-1 ) {
        pq.push( { A[i][W-1], i, W-1 } );
        used[i][W-1] = 1;
    }
    rep3( i, 1, W-1 ) {
        pq.push( { A[H-1][i], H-1, i } );
        used[H-1][i] = 1;
    }

    // ...
    int ans = H * W;
    vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    rep3( i, 1, Y+1 ) {
        // ...
        rep( d, 0, 4 ) {
            int ny = a[1] + dy[d], nx = a[2] + dx[d];
            if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
            if (a[0] > i && used[ny][nx] == 0) {
                used[ny][nx] = 1;
                pq.push( {A[ny][nx], ny, nx} );
            }
        }
        // ...
    }
    // ...
}