#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> v;
    void down(int i) {
        int low = i, l = 2*i+1, r = 2*i+2;
        if (l < v.size() && v[l] < v[low]) low = l;
        if (r < v.size() && v[r] < v[low]) low = r;
        if (low != i) { swap(v[i], v[low]); down(low); }
    }
public:
    void insert(int s) {
        v.push_back(s);
        int i = v.size()-1;
        while (i && v[(i-1)/2] > v[i]) { swap(v[i], v[(i-1)/2]); i = (i-1)/2; }
    }
    int extract() {
        int m = v[0]; v[0] = v.back(); v.pop_back();
        if(!v.empty()) down(0);
        return m;
    }
    void display() { for(int x: v) cout << x << "KB "; cout << endl; }
};
int main()
{
    MinHeap memory;
    memory.insert(128); memory.insert(64); memory.insert(256);
    cout << "Available Blocks: "; memory.display();
    cout << "Allocating Smallest: " << memory.extract() << "KB\n\n";
}