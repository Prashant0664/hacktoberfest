#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
    public:
    long long solve(int n, vector <int>& A, int m) 
    {
        vector <int> map((2 * n + 1), 0);
        long long currentIndex = n, count = 0, output = 0;
        map[currentIndex]++;
        
        for (int i = 0; i < n; i++) 
        {
            if (A[i] >= m) {
                count += map[currentIndex];
                currentIndex += 1;
            }
            else
            {
                count -= map[currentIndex - 1];
                currentIndex -= 1;
            }
            
            output += count;
            map[currentIndex]++;
        }
        
        return output;
    }

    long long countSubarray(int N, vector <int> A, int M) 
    {
        return solve(N, A, M) - solve(N, A, M + 1);
    }
};

int main() 
{
    int N, M;
    cin >> N >> M;
    vector <int> A(N);

    for (int i = 0; i < N; i++) 
    {
        cin >> A[i];
    }

    Solution obj;
    long long result = obj.countSubarray(N, A, M);
    cout << result << endl;

    return 0;
}