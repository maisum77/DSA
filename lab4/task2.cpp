#include <iostream>
using namespace std;
class Students
{
public:
    int id, marks;
    Students(int id, int marks)
    {
        this->id = id;
        this->marks = marks;
    }
    Students()
    {
        id = 0;
        marks = 0;
    }
};
int partition(Students s[], int st, int end)
{
    int idx = st - 1;
    int pivot = s[end].marks;
    for (int j = st; j < end; j++)
    {
        if (s[j].marks <= pivot)
        {
            idx++;
            swap(s[j].marks, s[idx].marks);
            swap(s[j].id, s[idx].id);
        }
    }
    swap(s[idx + 1], s[end]);
    return idx + 1;
}

void quicksort(Students s[], int st, int end)
{
    if (st < end)
    {
        int pivot = partition(s, st, end);
        quicksort(s, st, pivot - 1);
        quicksort(s, pivot + 1, end);
    }
}
int main()
{
    Students s[5] = {
        Students{101, 85},
        Students{102, 92},
        Students{103, 85},
        Students{104, 70},
        Students{105, 92},
    };
    int n = 5;

    cout << "Before Sorting: " << endl
         << "ID  | Marks" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << s[i].id << " | " << s[i].marks << endl;
    }

    quicksort(s, 0, n - 1);

    cout << "After Sorting: " << endl
         << "ID  | Marks" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << s[i].id << " | " << s[i].marks << endl;
    }
}