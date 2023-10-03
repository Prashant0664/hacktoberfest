#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int> numbers;
        int fact = 1;
        
        // Calculate the factorial of n and populate the numbers vector
        for (int i = 1; i <= n; i++) {
            fact = fact * i;
            numbers.push_back(i);
        }
        
        int blockSize = fact / n;
        k = k - 1;
        
        while (true) {
            // Append the selected number to the answer
            ans += to_string(numbers[k / blockSize]);
            
            // Remove the selected number from the available numbers
            numbers.erase(numbers.begin() + k / blockSize);
            
            // If all numbers have been used, break the loop
            if (numbers.empty()) {
                break;
            }
            
            // Update k and blockSize for the next iteration
            k = k % blockSize;
            blockSize = blockSize / numbers.size();
        }
        
        return ans;
    }
};

int main() {
    Solution solution;
    int n = 4;  // Example values
    int k = 9;
    string result = solution.getPermutation(n, k);
    cout << "Result: " << result << endl;
    return 0;
}
