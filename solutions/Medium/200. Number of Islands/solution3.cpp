class UnionFind {
public:
    UnionFind(vector<vector<char>>& grid) {
        count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * n + j);
                    ++count;
                }
                else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }

    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
            --count;
        }
    }

    int getCount() const {
        return count;
    }

private:
    vector<int> parent;
    vector<int> rank;
    int count;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num_rows = grid.size(), num_cols = grid[0].size();
        UnionFind uf(grid);
        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < num_cols; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    if (i >= 1 && grid[i - 1][j] == '1') uf.unite(i * num_cols + j, (i - 1) * num_cols + j);
                    if (i < num_rows - 1 && grid[i + 1][j] == '1') uf.unite(i * num_cols + j, (i + 1) * num_cols + j);
                    if (j >= 1 && grid[i][j - 1] == '1') uf.unite(i * num_cols + j, i * num_cols + j - 1);
                    if (j < num_cols - 1 && grid[i][j + 1] == '1') uf.unite(i * num_cols + j, i * num_cols + j + 1);
                }
            }
        }
        return uf.getCount();
    }
};
