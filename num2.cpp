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

void SortByRating(vector<Student>&students);

int main()
{
    Student Freder;
    Freder.Name = "Freder";
    Student Andrey;
    Andrey.Name = "Andrey";
    Student Katty;
    Katty.Name = "Katty";
    Freder.Ratings = {5, 5, 5, 4};
    Andrey.Ratings = {3, 4, 4, 3};
    Katty.Ratings = {5, 5, 5, 5};
    
    vector<Student> students = {Freder, Katty, Andrey};
    
    SortByRating(students);
    
    cout << students[0].Name << " " << students[1].Name << " "<< students[2].Name << endl;
    return 0;
}
