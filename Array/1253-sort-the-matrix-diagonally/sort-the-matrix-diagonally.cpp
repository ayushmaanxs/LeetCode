class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) { 
        int m = mat.size();
        int n = mat[0].size();
        // top row se diagonals start
        for(int col = 0; col < n; col++) {
            vector<int> temp;
            int i = 0, j = col;
            while(i < m && j < n) {
                temp.push_back(mat[i][j]);
                i++;
                j++;
            }
            sort(temp.begin(), temp.end());
            i = 0, j = col;
            int k = 0;
            while(i < m && j < n) {
                mat[i][j] = temp[k++];
                i++;
                j++;
            }
        }

        // left column se diagonals start (row 1 se, warna repeat hoga)
        for(int row = 1; row < m; row++) {
            
            vector<int> temp;
            int i = row, j = 0;

            while(i < m && j < n) {
                temp.push_back(mat[i][j]);
                i++;
                j++;
            }

            sort(temp.begin(), temp.end());

            i = row, j = 0;
            int k = 0;

            while(i < m && j < n) {
                mat[i][j] = temp[k++];
                i++;
                j++;
            }
        }

        return mat;
    }
};