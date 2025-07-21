using Graph = vector<vector<pair<int, int>>>; // Use int for edge weights
   ```

2. **Input Parsing**:
   - Read the number of vertices and edges.
   - Read the vertex weights and store them in a vector.
   - Read the edges and construct the graph.

3. **Path Finding Algorithm**:
   - Use Dijkstra's algorithm to find the shortest path from vertex 1 to every other vertex.
   - Keep track of the shortest distance to each vertex using a priority queue (min-heap).

4. **Output**:
   - Store the shortest distances in a vector.
   - Print the distances for vertices 2 to N.

### Example Code Snippets

Here's an example of how to parse the input and perform Dijkstra's algorithm: