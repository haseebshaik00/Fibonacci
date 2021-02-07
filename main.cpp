#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000;
int f[MAX] = {0};

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

int fibMatrix(int n)
{
	int F[2][2] = {{1,1},{1,0}};
	if (n == 0 || n==1)
		return n;
	int M[2][2] = {{1,1},{1,0}};
	for(int i=2;i<n;i++)
	{
        int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
        int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
        int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
        int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];
        F[0][0] = x;
        F[0][1] = y;
        F[1][0] = z;
        F[1][1] = w;
    }
	return F[0][0];
}

void multiply(int F[2][2], int M[2][2])
{
	int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
	int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
	int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
	int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];
	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}

void power(int F[2][2], int n)
{
	if(n == 0 || n == 1)
	    return;
	int M[2][2] = {{1, 1},{1, 0}};
	power(F, n / 2);
	multiply(F, F);
	if (n % 2 != 0)
		multiply(F, M);
}

int fibMatrixOpt(int n)
{
	int F[2][2] = {{1, 1},{1, 0}};
	if (n == 0)
		return 0;
	power(F, n - 1);
	return F[0][0];
}

int fibRecurrenceRelation(int n)
{
	if (n == 0)
		return 0;
	if (n == 1 || n == 2)
		return (f[n] = 1);
	if (f[n])
		return f[n];
	int k = (n & 1)? (n+1)/2 : n/2;
	f[n] = (n & 1)? (fibRecurrenceRelation(k)*fibRecurrenceRelation(k) +
                  fibRecurrenceRelation(k-1)*fibRecurrenceRelation(k-1)) :
                (2*fibRecurrenceRelation(k-1) + fibRecurrenceRelation(k))*fibRecurrenceRelation(k);
	return f[n];
}

int fibFormula(int n)
{
    double phi = (1 + sqrt(5)) / 2;
    return round(pow(phi, n) / sqrt(5));
}

int fibMatrixExp(int n)
{
	int F[2][2] = {{1, 1},{1, 0}};
	if (n == 0)
		return 0;
	power(F, n - 1);
	return F[0][0];
}

int main()
{
    //https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
    cout<<"**********Menu**********"<<endl;
    cout<<"1. Fibonacci Normal - Time:O(n) ; Space: O(1)"<<endl;
    cout<<"2. Fibonacci Recursion - Time:O(2^n) ; Space:O(n)"<<endl;
    cout<<"3. Fibonacci Top Down DP - Time:O(n) ; Space:O(n)"<<endl;
    cout<<"4. Fibonacci Bottom Up DP - Time:O(n) ; Space:O(n)"<<endl;
    cout<<"5. Fibonacci Bottom Up DP Optimized - Time:O(n) ; Space:O(1)"<<endl;
    cout<<"6. Fibonacci Using Matrix - Time:O(n) ; Space:O(1)"<<endl;
    cout<<"7. Fibonacci Using Matrix Optimized - Time:O(log n) ; Space:O(log n)"<<endl;
    cout<<"8. Fibonacci Using Matrix New Recurrence Relation - Time:O(log n) ; Space:O(n)"<<endl;
    cout<<"9. Fibonacci Using Matrix Formula - Time:O(1) ; Space:O(1)"<<endl;
    cout<<"10. Fibonacci Matrix Exponentiation - Time:O(log n) ; Space:O(log n)"<<endl;
    cout<<endl<<"Enter your choice  : ";
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
        case 6 :    {
                        int n;
                        cin>>n;
                        cout<<fibMatrix(n)<<endl;
                        break;
                    }
        case 7 :    {
                        int n;
                        cin>>n;
                        cout<<fibMatrixOpt(n)<<endl;
                        break;
                    }
        case 8 :    {
                        int n;
                        cin>>n;
                        cout<<fibRecurrenceRelation(n)<<endl;
                        break;
                    }
        case 9 :    {
                        int n;
                        cin>>n;
                        cout<<fibFormula(n)<<endl;
                        break;
                    }
        case 10 :    {
                        int n;
                        cin>>n;
                        cout<<fibMatrixExp(n)<<endl;
                        break;
                    }
        default :   {
                        cout<<"Try Again!"<<endl;
                        break;
                    }
    }
    return 0;
}
