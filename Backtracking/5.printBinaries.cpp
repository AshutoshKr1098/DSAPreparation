#include<bits/stdc++.h>
using namespace std;
void generateBinaries(int i,int n,string binary,vector<string>&binaries)
{
    if(i>n)
        return;
    if(i==n)
    {
        binaries.push_back(binary);
        return;
    }
    binary.push_back('0');
    generateBinaries(i+1,n,binary,binaries);
    binary.pop_back();
    binary.push_back('1');
    generateBinaries(i+1,n,binary,binaries);
    return;
}
int main()
{
    int n;
    cin>>n;
    vector<string> binaries;
    string binary = "";
    generateBinaries(0, n, binary, binaries);
    for(auto it:binaries)
        cout << it << endl;
}