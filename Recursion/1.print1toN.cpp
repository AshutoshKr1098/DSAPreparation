#include<bits/stdc++.h>
using namespace std;
void print(int n)
{
    //base condition
    if(n==0)
        return;
    //hypothesis
    print(n - 1);
    //induction
    cout << n << " ";
    return;
}
void printRev(int n)
{
    //base
    if(n==0)
        return;
    //induction
    cout << n << " ";
    //hypothesis
    printRev(n - 1);
    return;
}
int main()
{
    int n;
    cin >> n;
    print(n);
    cout << endl;
    printRev(n);
}