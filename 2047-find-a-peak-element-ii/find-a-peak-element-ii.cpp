class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    int l = 0, h = m - 1;
    while (l <= h) {
        int mid = l + (h - l) / 2, row = 0;
        for (int i = 1; i < n; i++)
            if (mat[i][mid] > mat[row][mid]) row = i;
        int left  = mid > 0     ? mat[row][mid-1] : -1;
        int right = mid < m - 1 ? mat[row][mid+1] : -1;
        if (mat[row][mid] > left && mat[row][mid] > right) return {row, mid};
        if (right > mat[row][mid]) l = mid + 1;
        else h = mid - 1;
    }
    return {-1, -1};
}
};