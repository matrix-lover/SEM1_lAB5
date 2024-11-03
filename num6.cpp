#include <iostream>
#include <vector>

using namespace std;
struct Student{
    string Name;
    string GroupId;
    vector<unsigned> Ratings;
    vector<string> Subject;
    Student* next;
};
#include "header.hpp"

vector<string> GroupsId(const vector<Student>&students);

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
    

    vector<string> Groups = GroupsId(students);
    
    for (int i = 0; i < Groups.size(); ++i)
    {
        cout << Groups[i] << endl;
    }
    return 0;
}
