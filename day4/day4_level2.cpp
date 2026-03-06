#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    std::vector<std::string> grid;
    std::ifstream file("day4_level2.txt");
    std::string line;

    while (std::getline(file, line)) {
    if (!line.empty())
        grid.push_back(line);
    }

    int rows = grid.size();
    int cols = grid[0].size();

    const int dr[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
    const int dc[8] = {-1, 0, 1,-1, 1,-1, 0, 1};

    int accessible = 1;
    int answer = 0;

    while(accessible!=0)
    {
        accessible = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] != '@')
                    continue;

                int neigh = 0;
                for (int k = 0; k < 8 and neigh < 4; ++k) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if (nr < 0 or nr >= rows or nc < 0 or nc >= cols)
                        continue;
                    if (grid[nr][nc] == '@')
                        ++neigh;
                }
                if (neigh < 4)
                {
                    ++accessible;
                    grid[r][c] = '.';
                }
            }
        }
        answer += accessible;
    }
   
    std::cout << answer << '\n';
    return 0;
}