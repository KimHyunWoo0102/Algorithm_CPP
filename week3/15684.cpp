#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

// Global variables for the game board dimensions and data
int arr[15][340];
int r, c, m;
vector<pair<int, int>> v; // Stores potential ladder positions

// Function to check if the current ladder configuration is valid
bool check() {
    // Iterate through each starting vertical line (column)
    for (int i = 1; i <= c; ++i) {
        int current_col = i;
        
        // Simulate moving down row by row
        for (int j = 1; j <= r; ++j) {
            // Check for a ladder to the left
            if (current_col > 1 && arr[j][current_col - 1] == 1) {
                current_col--;
            } 
            // Check for a ladder to the right
            else if (current_col < c && arr[j][current_col] == 1) {
                current_col++;
            }
        }
        
        // If the player doesn't end up on their starting line, the configuration is invalid
        if (current_col != i) {
            return false;
        }
    }
    // All players ended up on their starting lines
    return true;
}

// Function to check if a ladder can be placed at a specific position without overlaps
bool can_ladder(int y, int x) {
    // Check the current position
    if (arr[y][x] == 1) {
        return false;
    }
    // Check the position to the left
    if (x > 1 && arr[y][x - 1] == 1) {
        return false;
    }
    // Check the position to the right
    if (x < c && arr[y][x + 1] == 1) {
        return false;
    }
    
    return true;
}

// Recursive backtracking function to find a solution with a given number of ladders
bool solve(int count, int max_ladders, int start_idx) {
    // Base case: If the target number of ladders has been placed, check if the game is valid
    if (count == max_ladders) {
        return check();
    }
    
    // Iterate through all potential ladder positions to try placing the next ladder
    for (int i = start_idx; i < v.size(); ++i) {
        int y = v[i].first;
        int x = v[i].second;

        if (can_ladder(y, x)) {
            // Place the ladder
            arr[y][x] = 1;
            
            // Recursively call with an increased count and updated start index
            if (solve(count + 1, max_ladders, i + 1)) {
                return true; // A solution was found
            }
            
            // Backtrack: Remove the ladder to explore other possibilities
            arr[y][x] = 0;
        }
    }
    
    return false; // No solution found with the current path
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    // Get input for rows, existing ladders, and columns
    cin >> r >> m >> c;
    
    // Read the existing ladders and mark them on the board
    for (int i = 0; i < m; ++i) {
        int y, x;
        cin >> y >> x;
        arr[y][x] = 1;
    }
    
    // Store all empty positions in a vector to easily iterate through them
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j < c; ++j) {
            // A potential ladder position must not have an existing ladder
            // or an adjacent ladder to its left
            if (arr[i][j] == 0) {
                if (j > 1 && arr[i][j - 1] == 1) {
                    continue;
                }
                v.push_back({i, j});
            }
        }
    }
    
    // Check for a solution with 0, 1, 2, or 3 additional ladders
    for (int k = 0; k <= 3; ++k) {
        if (solve(0, k, 0)) {
            cout << k << '\n';
            return 0;
        }
    }

    // If no solution is found with up to 3 ladders, output -1
    cout << -1 << '\n';
    return 0;
}