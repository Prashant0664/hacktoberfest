class Solution:
	def distinctSubsequences(self, S):
		n=len(S)
		dp=[1]+[0]*n
		mod=10**9+7
		lo=[-1]*26
		for k in range(n):
		    idx=ord(S[k])-97
			if lo[idx]!=-1:
		        rep=dp[lo[idx]]
		    else:
		        rep=0
		    dp[k+1]=(2*dp[k]-rep)%mod
		    lo[idx]=k
        return dp[n]
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		s = input()

		ob = Solution()
		answer = ob.distinctSubsequences(s)
		print(answer)

# } Driver Code Ends