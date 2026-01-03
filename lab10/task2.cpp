#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> v;
    void up(int i) {
        if (i && v[(i-1)/2] < v[i]) {
            swap(v[i], v[(i-1)/2]);
            up((i-1)/2);
        }
    }
    void down(int i) {
        int big = i, l = 2*i+1, r = 2*i+2;
        if (l < v.size() && v[l] > v[big]) big = l;
        if (r < v.size() && v[r] > v[big]) big = r;
        if (big != i) { swap(v[i], v[big]); down(big); }
    }
public:
    void push(int p) { v.push_back(p); up(v.size()-1); }
    int pop() {
        int res = v[0]; v[0] = v.back(); v.pop_back();
        if(!v.empty()) down(0);
        return res;
    }
    void print() { for(int x: v) cout << x << " "; cout << endl; }
};
int main()
{
    MaxHeap scheduler;
    scheduler.push(10); 
    scheduler.push(50); 
    scheduler.push(30);
    cout << "Heap: "; scheduler.print();
    cout << "Executing Highest Priority: " << scheduler.pop() << "\n\n";
    cout << "Heap after deletion : "; scheduler.print();

}