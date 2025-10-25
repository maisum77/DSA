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

void merge(Students s[], int st, int mid, int end)
{
    int size = end - st + 1;
    Students temp_st[size];
    int i = st;
    int j = mid + 1;
    int count = 0;
    while (i <= mid && j <= end)
    {
        if (s[i].marks <= s[j].marks)
        {
            temp_st[count].id = s[i].id;
            temp_st[count].marks = s[i].marks;
            i++;
        }
        else
        {

            temp_st[count].id = s[j].id;
            temp_st[count].marks = s[j].marks;
            j++;
        }
        count++;
    }
    // fro remain element in the left side
    while (i <= mid)
    {
        temp_st[count].id = s[i].id;
        temp_st[count].marks = s[i].marks;
        i++;
        count++;
    }
    // for right side
    while (j <= end)
    {
        temp_st[count].id = s[j].id;
        temp_st[count].marks = s[j].marks;
        j++;
        count++;
    }
    // put the temp data into actual objects
    for (int idx = 0; idx < size; idx++)
    {
        s[idx + st].id = temp_st[idx].id;
        s[idx + st].marks = temp_st[idx].marks;
    }
}

void mergesort(Students s[], int st, int end)
{
    if (st < end) // base case so that the recursive dont just run infinately
    {
        int mid = st + (end - st) / 2;
        // for left side to further sort
        mergesort(s, st, mid);
        // for right side to further divide
        mergesort(s, mid + 1, end);
        // function to merge the arr
        merge(s, st, mid, end);
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
         << "ID  | Marks"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << s[i].id << " | " << s[i].marks << endl;
    }

    mergesort(s, 0, n - 1);

    cout << "After Sorting: " << endl
         << "ID  | Marks"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << s[i].id << " | " << s[i].marks << endl;
    }
}
