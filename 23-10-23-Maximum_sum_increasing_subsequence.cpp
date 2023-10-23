/*
Problem Descritption: Maximum sum increasing subsequence

Given an array of n positive integers. Find the sum of the maximum sum subsequence of the given array such that the integers in the subsequence are sorted in strictly increasing order i.e. a strictly increasing subsequence. 

Example 1:

Input: 
N = 5, arr[] = {1, 101, 2, 3, 100} 
Output: 
106
Explanation:
The maximum sum of a increasing sequence is obtained from {1, 2, 3, 100},
Example 2:

Input: 
N = 4, arr[] = {4, 1, 2, 3}
Output: 
6
Explanation:
The maximum sum of a increasing sequence is obtained from {1, 2, 3}.
Your Task:  
You don't need to read input or print anything. Complete the function maxSumIS() which takes N and array arr as input parameters and returns the maximum value.

Expected Time Complexity: O(N^2)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 10^3
1 ≤ arr[i] ≤ 10^5

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int>dp(n,0);
	    
	    dp[0]=arr[0];
	    int ans=arr[0];
	    
	    for(int i=1; i<n; i++){
	        for(int j=i-1; j>=0; j--){
	            if(arr[j]<arr[i])
	                dp[i]=max(dp[i],dp[j]);
	        }
	        dp[i]+=arr[i];
	        ans = max(ans,dp[i]);
	    }
	    
	    return ans;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
