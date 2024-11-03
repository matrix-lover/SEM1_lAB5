#include <iostream>
#include <vector>

using namespace std;
struct Student{
    string Name;
    string GroupId;
    vector<unsigned> Ratings;
    vector<string> Subject;
};

struct Group
{
    string Id;
    vector<Student> studentsInGroup;
};

vector<Group> Groups(vector<Student>&students)
{
    vector<Group> GroupsOfStudents; // вектор объектов структуры Group
    int count_1_0 = 0;
    
    for(const Student&student : students) // указываем на вектор students, и перебираем его объекты(студентов)
    {
        for(Group&group : GroupsOfStudents) // указываем на вектор GroupsStudents и перебираем его объекты
        {
            if(student.GroupId == group.Id) // если уже есть объекты(группы) с такими названиями в векторе GroupsStudents
            {
                group.studentsInGroup.push_back(student);
                count_1_0 += 1;
                break;
            }
        }
        if(count_1_0 == 0) // если название группы сткдента еще не встречалось, создаем новый объект GroupsStudents
        {
            Group newgroup; // инициализируем объект в структуре
            newgroup.studentsInGroup.push_back(student); // связываем с данным студентом из вектора students
            newgroup.Id = student.GroupId; // название группы
            GroupsOfStudents.push_back(newgroup); // инициализируем объект в векторе
        }
        count_1_0 = 0;
    }
    return GroupsOfStudents;
}

void student_data(const Student&student)
{
    cout << "Name: " << student.Name << '\n' << "Группа: " << student.GroupId << endl;
}

void subj_rate(const Student&student)
{
    for(int i = 0; i < student.Subject.size(); ++i)
    {
        cout << student.Subject[i] << ": " << student.Ratings[i] << endl;
    }
}


int main()
{
    Student Freder;
    Student Andrey;
    Student Katty;
    
    Freder.Name = "Freder";
    Andrey.Name = "Andrey";
    Katty.Name = "Katty";
    
    Freder.Ratings = {4, 4};
    Andrey.Ratings = {5, 3};
    Katty.Ratings = {5, 5};
    
    Freder.Subject = {"Math", "History"};
    Andrey.Subject = {"Math", "History"};
    Katty.Subject = {"Math", "History"};
    
    Freder.GroupId = "gamma";
    Andrey.GroupId = "betta";
    Katty.GroupId = "gamma";
    
    vector<Student> students = {Freder, Katty, Andrey};
    
    vector<Group> GroupsOfStudents = Groups(students); // сортируем студентов по группам
    
    for (const Group& curgroup : GroupsOfStudents)
    {
        cout << "<<<" << "Группа: " << curgroup.Id << ">>>" << '\n' << endl;
        for(const Student&student : curgroup.studentsInGroup)
        {
            student_data(student);
            subj_rate(student);
            cout << '\n';
        }
        cout << "<<<" <<"End of list" << ">>>" << '\n' << endl;
    }
    return 0;
}
