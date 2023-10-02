#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long solve(int n, vector<int>& A, int m) {

        vector<int> mp(2*n+1, 0);
        long long cur = n, tot = 0, ans = 0;
        mp[cur]++;
        for (int i = 0; i < n; i++) {
            if (A[i] >= m) {
                tot += mp[cur];
                cur += 1;
            }
            else {
                tot -= mp[cur - 1];
                cur -= 1;
            }
            ans += tot;
            mp[cur]++;
        }
        return ans;
    }

    long long countSubarray(int N, vector<int> A, int M) {

        return solve(N, A, M) - solve(N, A, M + 1);
    }
};

int main() {
    int N, M;
    cout << "Enter the value of N: ";
    cin >> N;
    cout << "Enter the value of M: ";
    cin >> M;
    
    vector<int> A(N);
    cout << "Enter " << N << " elements for array A: ";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    Solution s;
    long long result = s.countSubarray(N, A, M);
    
    cout << "Output: " << result << endl;
    
    return 0;
}
