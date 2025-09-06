#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <int> vec={10,20,30,40,50};
    vector<int> vec1(3,0);//it show that size of 3 vector created and all value is 0
    cout<<vec[0]<<endl;
    for(int i: vec1){
        cout<<i<<endl;
    }
    return 0;
}