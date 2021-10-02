/*
Question Link : https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1
Given two strings. The task is to find the length of the longest common substring.


Example 1:

Input: S1 = "ABCDGH", S2 = "ACDGHR"
Output: 4
Explanation: The longest common substring
is "CDGH" which has length 4.
*/

int longestCommonSubstr (string s1, string s2, int n, int m)
{
        // your code here
        int dp[n+1][m+1];
        int i,j,maxLength=0;
        for(i=0;i<=n;i++)
            dp[i][0] = 0;             //first row
        for(i=0;i<=m;i++)
            dp[0][i] = 0;             // first column
            
        for(i = 1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    if(maxLength < dp[i][j])
                        maxLength = dp[i][j];
                }
                else
                    dp[i][j] = 0;
            }
        }
        return maxLength;
    }
