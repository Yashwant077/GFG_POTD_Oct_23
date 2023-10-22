/*
Problem Description: Number of paths

The problem is to count all the possible paths from top left to bottom right of an MxN matrix with the constraints that from each cell you can either move to right or down.

Return answer modulo 109+7.

Example 1:

Input:
M = 3 and N = 3
Output: 6
Explanation:
Let the given input 3*3 matrix is filled 
as such:
A B C
D E F
G H I
The possible paths which exists to reach 
'I' from 'A' following above conditions 
are as follows:ABCFI, ABEHI, ADGHI, ADEFI, 
ADEHI, ABEFI

Example 2:

Input:
M = 1 and N = 4
Output: 1
Explanation:
There is only one direction to go in,
and thus, there is only one path possible.
Your Task
You don't need to read input or print anything. Your task is to complete the function numberOfPaths() which takes the integer M and integer N as input parameters and returns an integer, the number of paths.

Expected Time Complexity: O(M)
Expected Space Complexity: O(1)

Constraints:
1 ≤ N ≤ 10^8
1 ≤ M ≤ 10^5

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution
{
    public:
    
    long long calculateInverse(long long a, long long b, long long m){
        long long res = 1;
        
        while(b>0){
            if(b&1==1)
                res = (res*1ll*a)%m;
            a=(a*1ll*a)%m;
            b=b/2;
        }
        
        return res;
    }
    
    long long  numberOfPaths(int M, int N)
    {
        // Code Here
        long long mod = 1e9+7;
        
        long long m = M%mod;
        long long n = N%mod;
        long long c = ((n+m)%mod-2)%mod;
        long long d = (m-1)%mod;
        long long ans = 1;
        
        for(int i=1; i<=d; i++){
            ans = ((ans%mod)*(c%mod))%mod;
            
            ans = ((ans)*calculateInverse(i,mod-2,mod)%mod)%mod;
            
            c--;
        }
        
        return ans%mod;
        
    }
};


//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N, M;
		cin>>M>>N;
		Solution ob;
	    cout << ob.numberOfPaths(M, N)<<endl;
	}
    return 0;
}
// } Driver Code Ends
