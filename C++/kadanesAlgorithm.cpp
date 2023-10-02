#include <iostream>
#include <climits>

//Kadane's Algorithm
long long maxSubarraySum(int a[], int n)
{
    long long maxh = 0, maxf = a[0];

    for (int i = 0; i < n; i++)
    {
        maxh += a[i];

        if (maxf < maxh)
            maxf = maxh;

        if (maxh < 0)
            maxh = 0;
    }

    return maxf;
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);

    long long result = maxSubarraySum(a, n);

    std::cout << "Maximum Subarray Sum: " << result << std::endl;

    return 0;
}