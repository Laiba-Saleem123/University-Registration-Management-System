#include<iostream>
#include<string>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person()
    {
        name = "";
        age = 0;
    }

    Person(string n, int a)
    {
        name = n;
        age = a;
    }

    virtual void displayPerson()
    {
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
    }

    virtual ~Person() {}
};

class Student : public Person
{
protected:
    int studentID;
    string department;

public:
    Student() : Person()
    {
        studentID = 0;
        department = "";
    }

    Student(string n, int a, int id, string dept)
        : Person(n, a)
    {
        studentID = id;
        department = dept;
    }

    int getID()
    {
        return studentID;
    }

    virtual void displayStudent()
    {
        displayPerson();
        cout << "\nStudent ID: " << studentID;
        cout << "\nDepartment: " << department;
    }

    virtual ~Student() {}
};

class Registration : public Student
{
private:
    string courseName;
    float fee;

public:
    Registration(string n, int a, int id,
                 string dept, string course, float f)
        : Student(n, a, id, dept)
    {
        courseName = course;
        fee = f;
    }

    void displayStudent()
    {
        cout << "\n\nSTUDENT RECORD";
        cout << "\nName : " << name;
        cout << "\nAge : " << age;
        cout << "\nStudent ID : " << studentID;
        cout << "\nDepartment : " << department;
        cout << "\nCourse : " << courseName;
        cout << "\nFee : " << fee << endl;
    }
};

class UniversitySystem
{
private:
    Student* students[100];
    int count;

public:
    UniversitySystem()
    {
        count = 0;

        for(int i = 0; i < 100; i++)
        {
            students[i] = NULL;
        }
    }

    void addStudent()
    {
        if(count >= 100)
        {
            cout << "\nLimit reached!\n";
            return;
        }

        string name, dept, course;
        int age, id;
        float fee;

        cin.ignore();

        cout << "\nEnter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter ID: ";
        cin >> id;

        cin.ignore();

        cout << "Enter Department: ";
        getline(cin, dept);

        cout << "Enter Course: ";
        getline(cin, course);

        cout << "Enter Fee: ";
        cin >> fee;

        students[count] =
            new Registration(name, age, id, dept, course, fee);

        count++;

        cout << "\nStudent Added Successfully!\n";
    }
        void displayStudents()
    {
        if(count == 0)
        {
            cout << "\nNo Records Found!\n";
            return;
        }

        for(int i = 0; i < count; i++)
        {
            if(students[i] != NULL)
            {
                students[i]->displayStudent();
            }
        }
    }

    void searchStudent()
    {
        int id;
        bool found = false;

        cout << "\nEnter Student ID: ";
        cin >> id;

        for(int i = 0; i < count; i++)
        {
            if(students[i] != NULL &&
               students[i]->getID() == id)
            {
                students[i]->displayStudent();
                found = true;
                break;
            }
        }

        if(!found)
        {
            cout << "\nStudent Not Found!\n";
        }
    }

    void deleteStudent()
    {
        int id;
        bool found = false;

        cout << "\nEnter Student ID: ";
        cin >> id;

        for(int i = 0; i < count; i++)
        {
            if(students[i] != NULL &&
               students[i]->getID() == id)
            {
                delete students[i];

                for(int j = i; j < count - 1; j++)
                {
                    students[j] = students[j + 1];
                }

                count--;
                students[count] = NULL;

                found = true;

                cout << "\nRecord Deleted Successfully!\n";
                break;
            }
        }

        if(!found)
        {
            cout << "\nStudent Not Found!\n";
        }
    }
        ~UniversitySystem()
    {
        for(int i = 0; i < count; i++)
        {
            delete students[i];
            students[i] = NULL;
        }
    }
};

int main()
{
    UniversitySystem system;
    int choice;

    do
    {
        cout << "\n\nUNIVERSITY REGISTRATION SYSTEM";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Search Student";
        cout << "\n4. Delete Student";
        cout << "\n5. Exit";
        cout << "\nEnter Choice: ";

        cin >> choice;

        switch(choice)
        {
            case 1:
                system.addStudent();
                break;

            case 2:
                system.displayStudents();
                break;

            case 3:
                system.searchStudent();
                break;

            case 4:
                system.deleteStudent();
                break;

            case 5:
                cout << "\nProgram Ended Successfully!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}
