#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student
{
public:
    int rollNo;
    string name;
    float marks;

    void input()
    {
        cout << "\nEnter Roll Number: ";
        cin >> rollNo;

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display()
    {
        cout << "\n-----------------------------";
        cout << "\nRoll Number : " << rollNo;
        cout << "\nName        : " << name;
        cout << "\nMarks       : " << marks;
        cout << "\n-----------------------------\n";
    }
};

int main()
{
    vector<Student> students;

    int choice;

    do
    {
        cout << "\n========== STUDENT MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
        {
            Student s;
            s.input();
            students.push_back(s);

            cout << "\nStudent Added Successfully!\n";
            break;
        }

        case 2:
        {
            if(students.empty())
            {
                cout << "\nNo Students Found.\n";
            }
            else
            {
                cout << "\nStudent Records:\n";

                for(int i=0;i<students.size();i++)
                {
                    students[i].display();
                }
            }
            break;
        }

        case 3:
        {
            if(students.empty())
            {
                cout << "\nNo Students Available.\n";
                break;
            }

            int roll;
            bool found=false;

            cout << "\nEnter Roll Number to Search: ";
            cin >> roll;

            for(int i=0;i<students.size();i++)
            {
                if(students[i].rollNo==roll)
                {
                    cout << "\nStudent Found!\n";
                    students[i].display();
                    found=true;
                    break;
                }
            }

            if(!found)
            {
                cout << "\nStudent Not Found.\n";
            }

            break;
        }

        case 4:
        {
            cout << "\nThank You for using the Student Management System!\n";
            break;
        }

        default:
        {
            cout << "\nInvalid Choice!\n";
        }

        }

    }while(choice!=4);

    return 0;
}
