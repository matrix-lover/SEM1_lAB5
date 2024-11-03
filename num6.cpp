#include <iostream>
#include <vector>

using namespace std;
struct Student{
    string Name;
    string GroupId;
    vector<unsigned> Ratings;
    vector<string> Subject;
};

vector<string> GroupsId(const vector<Student>&students)
{
    vector<string> groups_name;
    unsigned long number;
    number = students.size(); // количество студентов
    int count = 0;
    
    for(int i = 0; i < number; ++i) // перебираем студентов
    {
        for(int j = 0; j < groups_name.size(); ++j) // перебираем названия групп, уже записанных в Groups
        {
            if(students[i].GroupId == groups_name[j]) // если уже есть группа с таким же названием в массиве Groups
            {
                count += 1;
                break;
            }
        }
        if(count != 1) // если нет таких
        {
            groups_name.push_back(students[i].GroupId);
        }
        count = 0;
    }
    
    return groups_name;
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
    
    vector<string> groups_name = GroupsId(students);
    
    for (int i = 0; i < groups_name.size(); ++i)
    {
        cout << groups_name[i] << endl;
    }
    return 0;
}
