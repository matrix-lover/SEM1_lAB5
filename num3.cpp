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

size_t CountTwoness(const vector<Student>&students);

int main()
{
    Student Freder;
    Freder.Name = "Freder";
    Student Andrey;
    Andrey.Name = "Andrey";
    Student Katty;
    Katty.Name = "Katty";
    Freder.Ratings = {2, 4, 1, 3};
    Andrey.Ratings = {4, 5, 2, 4};
    Katty.Ratings = {5, 5, 5, 5};
    
    vector<Student> students = {Freder, Katty, Andrey};
    

    size_t count = CountTwoness(students);
    
    cout << count << endl;
    return 0;
}
