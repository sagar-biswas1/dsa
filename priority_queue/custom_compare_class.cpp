#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int roll;
    int marks;
    Student(string name, int roll, int marks)
    {
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};

class cmp
{
public:
    bool operator()(Student a, Student b)
    {
        if (a.marks <= b.marks)
            return true;
        else
            return false;
    }
};

int main()
{
    
    priority_queue<Student, vector<Student>, cmp> pq;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string name;
        int roll;
        int marks;
        cin >> name >> roll >> marks;

        Student st(name, roll, marks);
        pq.push(st);
    }
 Student st("hello", 7, 1000);
        pq.push(st);

while(!pq.empty()){
    Student st= pq.top();
    cout<< st.name << endl;
    pq.pop();
}
    return 0;
}
