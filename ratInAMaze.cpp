#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to check if it's safe to move to a particular cell
bool isSafe(int x, int y, vector<vector<int>>& maze, vector<vector<bool>>& visited, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && !visited[x][y]);
}

// Recursive function to find all paths
void findPaths(int x, int y, vector<vector<int>>& maze, int n, vector<string>& paths, string path, vector<vector<bool>>& visited) {
    // Base case: if destination is reached
    if (x == n - 1 && y == n - 1) {
        paths.push_back(path);
        return;
    }

    // Mark the current cell as visited
    visited[x][y] = true;

    // Move Down (D)
    if (isSafe(x + 1, y, maze, visited, n)) {
        findPaths(x + 1, y, maze, n, paths, path + 'D', visited);
    }

    // Move Left (L)
    if (isSafe(x, y - 1, maze, visited, n)) {
        findPaths(x, y - 1, maze, n, paths, path + 'L', visited);
    }

    // Move Right (R)
    if (isSafe(x, y + 1, maze, visited, n)) {
        findPaths(x, y + 1, maze, n, paths, path + 'R', visited);
    }

    // Move Up (U)
    if (isSafe(x - 1, y, maze, visited, n)) {
        findPaths(x - 1, y, maze, n, paths, path + 'U', visited);
    }

    // Unmark the current cell as visited (Backtrack)
    visited[x][y] = false;
}

// Function to display all the paths
void printPaths(vector<string>& paths) {
    if (paths.empty()) {
        cout << "No path found." << endl;
    } else {
        cout << "The possible paths are: " << endl;
        for (const string& path : paths) {
            cout << path << endl;
        }
    }
}

// Function to find all possible paths
void solveMaze(vector<vector<int>>& maze, int n) {
    vector<string> paths;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    if (maze[0][0] == 1) {
        findPaths(0, 0, maze, n, paths, "", visited);
    }
    printPaths(paths);
}

// Driver Code
int main() {
    int n;
    cout << "Enter the size of the maze (N): ";
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));

    cout << "Enter the maze matrix (1 for open, 0 for blocked):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    solveMaze(maze, n);
    
    return 0;
}
