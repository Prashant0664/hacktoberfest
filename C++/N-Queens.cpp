class Solution {
public:
    void solve(vector<vector<string>>&v, vector<string>& s, vector<int> left, vector<int>up, vector<int>down, int col, int n)
    {
        if(col==n)
        {
            v.push_back(s);
            return;
        }

        for(int row=0;row<n;row++)
        {
            if(left[row]==0 && up[(n-1)+(col-row)]==0 && down[row+col]==0)
            {
                s[row][col]='Q';
                left[row]=1;
                up[(n-1)+(col-row)]=1;
                down[row+col]=1;
                solve(v, s, left, up, down, col+1, n);
                s[row][col]='.';
                left[row]=0;
                up[(n-1)+(col-row)]=0;
                down[row+col]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>v;
        vector<string>s(n);
        string str(n,'.');
        for(int i=0;i<n;i++)
        s[i]=str;
        vector<int> left(n,0), up(2*n-1,0), down(2*n-1,0);
        solve(v, s, left, up, down, 0, n);
        return v;
    }
};
