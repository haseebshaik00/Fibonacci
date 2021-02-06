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

int fibTopDownDP(int n, int dp[])
{
    if(n==0 || n==1)
        return n;
    if(dp[n]!=0)
        return dp[n];
    int ans = fibTopDownDP(n-1, dp) + fibTopDownDP(n-2, dp);
    return dp[n]=ans;
}

int fibBottomUpDP(int n)
{
    int dp[100]={0};
    dp[1]=1;
    for(int i=2;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];
    return dp[n];
}

int fibBottomUpOptDP(int n)
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
    cout<<"3. Fibonacci Top Down DP - Time:O(n) ; Space:O(n)"<<endl;
    cout<<"4. Fibonacci Bottom Up DP - Time:O(n) ; Space:O(n)"<<endl;
    cout<<"5. Fibonacci Bottom Up DP Optimised - Time:O(n) ; Space:O(n)"<<endl<<endl;
    cout<<"Enter your choice  : ";
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
                        int dp[100]={0};
                        cout<<fibTopDownDP(n,dp)<<endl;
                        break;
                    }
        case 4 :    {
                        int n;
                        cin>>n;
                        cout<<fibBottomUpDP(n)<<endl;
                        break;
                    }
        case 5 :    {
                        int n;
                        cin>>n;
                        cout<<fibBottomUpOptDP(n)<<endl;
                        break;
                    }
        default :   {
                        cout<<"Try Again!"<<endl;
                        break;
                    }
    }
    return 0;
}
