#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student
{
    int id;
    string name;
    float gpa;
};

class StudentManager
{
private:
    vector<Student> students;

public:
    void addStudent(int id, const string &name, float gpa)
    {
        students.push_back({id, name, gpa});
        cout << "Student added successfully!\n";
    }

    void displayAll() const
    {
        if (students.empty())
        {
            cout << "No records found.\n";
            return;
        }
        cout << "\n--- Student Records ---\n";
        for (const auto &s : students)
        {
            cout << "ID: " << s.id << " | Name: " << s.name << " | GPA: " << s.gpa << "\n";
        }
    }

    void searchById(int id) const
    {
        for (const auto &s : students)
        {
            if (s.id == id)
            {
                cout << "Found: " << s.name << " (GPA: " << s.gpa << ")\n";
                return;
            }
        }
        cout << "Student with ID " << id << " not found.\n";
    }
};

int main()
{
    StudentManager manager;
    int choice;

    do
    {
        cout << "\n1. Add Student\n2. View All\n3. Search by ID\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int id;
            string name;
            float gpa;
            cout << "Enter ID, Name, GPA: ";
            cin >> id >> name >> gpa;
            manager.addStudent(id, name, gpa);
        }
        else if (choice == 2)
        {
            manager.displayAll();
        }
        else if (choice == 3)
        {
            int id;
            cout << "Enter Search ID: ";
            cin >> id;
            manager.searchById(id);
        }
    } while (choice != 4);

    return 0;
}
