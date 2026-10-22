class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        // goal[f][r] = is state (f, r) equal to [0,1,...,n-1] ?
        vector<vector<char>> goal(2, vector<char>(n, 0));
        for (int r = 0; r < n; r++) {
            if (nums[r] != 0) continue;
            bool ok0 = true, ok1 = true;
            for (int i = 0; i < n; i++) {
                if (nums[(r + i) % n] != i) ok0 = false;
                if (nums[((r - i) % n + n) % n] != i) ok1 = false;
            }
            goal[0][r] = ok0;
            goal[1][r] = ok1;
        }

        vector<vector<int>> dist(2, vector<int>(n, -1));
        queue<pair<int,int>> q;
        dist[0][0] = 0;
        q.push({0, 0});

        while (!q.empty()) {
            auto [f, r] = q.front();
            q.pop();
            int d = dist[f][r];

            if (goal[f][r]) return d;

            int nf1, nr1, nf2, nr2;
            if (f == 0) {
                nf1 = 0; nr1 = (r + 1) % n;          // left rotate
                nf2 = 1; nr2 = (r - 1 + n) % n;      // reverse
            } else {
                nf1 = 1; nr1 = (r - 1 + n) % n;      // left rotate
                nf2 = 0; nr2 = (r + 1) % n;          // reverse
            }

            if (dist[nf1][nr1] == -1) {
                dist[nf1][nr1] = d + 1;
                q.push({nf1, nr1});
            }
            if (dist[nf2][nr2] == -1) {
                dist[nf2][nr2] = d + 1;
                q.push({nf2, nr2});
            }
        }
        return -1;
    }
};