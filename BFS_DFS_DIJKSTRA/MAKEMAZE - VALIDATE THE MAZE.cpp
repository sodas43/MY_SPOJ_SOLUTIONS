#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



/** ALGO:
 * ---------
 * 1. first check for r==0 and r==R-1, how many '.' capture the indexes(r,c).if it's more than 2, return 'invalid'.
 * 2. Now check same for c==0 and c==C-1 and do count++. If (count>2||count<2), return 'Invalid'.
 * 3. Otherwise, start from all the captured (r,c)'s contains '.'. Do bfs/dfs to reach to end.
 * 4. Now end is previously captured other (r,c). If able to reach, then 'Valid', else 'Invalid'.
 * 5. for dfs, need to goto 4 directions. make dx[] and dy[] accordingly.
 */
int entryX, entryY, exitX, exitY;
bool visited[21][21];
int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

int R, C;

bool checkMaze(vector<vector<char>> maze, int R, int C) {
    int cnt = 0;

    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if ((r == 0 || r == R - 1 || c == 0 || c == C - 1) &&
                    maze[r][c] == '.') {
                if (cnt == 0)        { entryX = r;  entryY = c; }
                else if (cnt == 1)   { exitX = r;  exitY = c; }
                else                { return false; }

                ++cnt;
            }
        }
    }
    if (cnt == 2)    return true;
    return false;
}

bool isValid(vector<vector<char>> maze, int r, int c) {
    return (r >= 0 && c >= 0 && r < R && c < C && maze[r][c] == '.');
}

bool dfs(vector<vector<char>> maze, int r, int c) {
    if (r == exitX && c == exitY)    return true;

    if (visited[r][c] == false)  {

        visited[r][c] = true;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (isValid(maze, nr, nc)) {
                if (dfs(maze, nr, nc)) { return true; }
            }
        }
    }
    return false;
}

bool isValidMaze(vector<vector<char>> maze, int R, int C) {
    bool hasOnlyTwoPoints = checkMaze(maze, R, C);
    if (hasOnlyTwoPoints) { // contain only two points(entry & exit)
        memset(visited, false, sizeof (visited));

        if (dfs(maze, entryX, entryY))   { return true; }
    }
    return false;
}

int main() {
    int T;
    cin >> T;

    while (T--) {

        cin >> R >> C;

        vector<vector<char>> maze(R, vector<char>(C, '0'));
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> maze[i][j];
            }
        }

        if (R == 1 && C == 1) {
            cout << "invalid" << endl;
            continue;
        }

        bool ans = isValidMaze(maze, R, C);

        if (ans) { cout << "valid" << endl;   }
        else    { cout << "invalid" << endl; }
    }
}