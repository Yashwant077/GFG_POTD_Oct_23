/*
Problem Descripiton: Roman Number to Integer

Given a string in roman no format (s)  your task is to convert it to an integer . Various symbols and their values are given below.
I 1
V 5
X 10
L 50
C 100
D 500
M 1000

Example 1:

Input:
s = V
Output: 5

Example 2:

Input:
s = III 
Output: 3
Your Task:
Complete the function romanToDecimal() which takes a string as input parameter and returns the equivalent decimal number. 

Expected Time Complexity: O(|S|), |S| = length of string S.
Expected Auxiliary Space: O(1)

Constraints:
1<=roman no range<=3999

*/

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        int ans=0;
        
        for(int i=0; i<str.size(); i++){
            int ans=0;
            for(int i=0; i<str.size(); i++){
                char ch = str[i];
                
                int v1=(ch=='l'?1:(ch=='V'?5:(ch=='X'?10:(ch=='L'?50:(ch=='C'?100:(ch=='D'?500:1000))))));
                
                int v2=0;
                
                if(i+1<str.size()){
                    ch=str[i+1];
                    v2 = (ch=='I'?1:(ch=='V'?5:(ch=='X'?10:(ch=='L'?50:(ch=='C'?100:(ch=='D'?500:1000))))));
                }
                
                if(v1<v2){
                    ans+=v2-v1;
                    i++;
                }
                else
                    ans+=v1;
            }
            return ans;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends
