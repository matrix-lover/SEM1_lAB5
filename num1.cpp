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


void SortByName(vector<Student>&students);



int main()
{
    Student Freder;
    Freder.Name = "Freder";
    Student Andrey;
    Andrey.Name = "Andrey";
    Student Katty;
    Katty.Name = "Katty";
    vector<Student> students = {Freder, Katty, Andrey};
    
    SortByName(students);
    
    cout << students[0].Name << " " << students[1].Name << " "<< students[2].Name << endl;
    return 0;
}
