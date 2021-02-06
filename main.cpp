#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    if(n==0 || n==1)
        return n;
    for(int i=0;i<n;i++)
    {

    }
}

int main()
{
    int ch;
    cin>>ch;
    cout<<"**********Menu**********"<<endl;
    cout<<"1. Fibonacci Normal - O()"<<endl;
    switch(ch)
    {
        case 1 :    {
                        int n;
                        cin>>n;
                        cout<<fibonacci(n)<<endl;
                    }
    }
    return 0;
}
