#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if(n==0 || n==1)
        return n;
    int a=0,b=1,c;
    for(int i=0;i<=n-2;i++)
    {
        c=a+b;
        a=b;b=c;
    }
    return c;
}

int fibRecursion(int n)
{
    if(n==0 || n==1)
        return n;
    return fibRecursion(n-1)+fibRecursion(n-2);
}

int fibTopDown(int n, int dp[])
{
    if(n==0 || n==1)
        return n;
    //Lookup
    if(dp[n]!=0)
        return dp[n];
    int ans = fibTopDown(n-1, dp) + fibTopDown(n-2, dp);
    return dp[n]=ans;
}

int fibBottomUp(int n)
{
    int dp[100]={0};
    dp[1]=1;
    for(int i=2;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];
    return dp[n];
}

int fibBottomUpOpt(int n)
{
    if(n==0 || n==1)
        return n;
    int a=0,b=1,c;
    for(int i=2;i<=n;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

int main()
{
    cout<<"**********Menu**********"<<endl;
    cout<<"1. Fibonacci Normal - Time:O(n) ; Space: O(1)"<<endl;
    cout<<"2. Fibonacci Recursion - Time:O(2^n) ; Space:O(n)"<<endl;
    cout<<"2. Fibonacci Top Down DP - Time:O(2^n) ; Space:O(n)"<<endl;
    cout<<"2. Fibonacci Bottom Up DP - Time:O(2^n) ; Space:O(n)"<<endl;
    int ch;
    cin>>ch;
    switch(ch)
    {
        case 1 :    {
                        int n;
                        cin>>n;
                        cout<<fib(n)<<endl;
                    }
        case 2 :    {
                        int n;
                        cin>>n;
                        cout<<fibRecursion(n)<<endl;
                        break;
                    }
        case 3 :    {
                        int n;
                        cin>>n;
                        cout<<fibTopDownDP(n)<<endl;
                        break;
                    }
        case 4 :    {
                        int n;
                        cin>>n;
                        cout<<fibBottomUpDP(n)<<endl;
                        break;
                    }
        default :   {
                        cout<<"Try Again!"<<endl;
                        break;
                    }
    }
    return 0;
}
