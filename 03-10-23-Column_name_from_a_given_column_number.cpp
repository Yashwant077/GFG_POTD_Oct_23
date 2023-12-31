/*
Problem Description: Column name from a given column number

Given a positive integer, return its corresponding column title as appear in an Excel sheet.
Excel columns has a pattern like A, B, C, … ,Z, AA, AB, AC,…. ,AZ, BA, BB, … ZZ, AAA, AAB ….. etc. In other words, column 1 is named as “A”, column 2 as “B”, column 27 as “AA” and so on.

Example 1:

Input:
N = 28
Output: AB
Explanation: 1 to 26 are A to Z.
Then, 27 is AA and 28 = AB.

Example 2:

Input: 
N = 13
Output: M
Explanation: M is the 13th character of
alphabet.
Your Task:
You don't need to read input or print anything. Your task is to complete the function colName() which takes the column number N as input and returns the column name represented as a string.
Expected Time Complexity: O(LogN).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 10^18

*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    using ll = long long int;
    string colName (long long int n)
    {
        // your code here
        string ans="";
        
        while(n>0)
        {
            ll val = n%26;
            n = n/26;
            
            if(val==0){
                ans.push_back('Z');
                n--;
            }
            else{
                char ch='A'+val-1;
                ans.push_back(ch);
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends
