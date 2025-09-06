#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<char> vec={'a','b','c','d','e'};
    cout<<"size of the vector is "<<vec.size();

    vector <int> vec1={10,20,30,40,50};
    vec1.push_back(60);
    cout<<"\nsize of the vector after push back is "<<vec1.size()<<endl;
    vec1.pop_back();
    cout<<"size of the vector after pop back is "<<vec1.size()<<endl;
    cout<<vec1.front()<<endl;
    cout<<vec1.back()<<endl;
    return 0;
}