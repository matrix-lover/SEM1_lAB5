#include <iostream>
#include <vector>

using namespace std;
struct Student{
    string Name;
    string GroupId;
    vector<unsigned> Ratings;
    vector<string> Subject;
};

vector<Student> VectorMathExellent(const vector<Student>&students)
{
    vector<Student> MathExellent;
    unsigned long number;
    number = students.size(); // количество студентов
    int index = 0; // индекс предмета в векторе Subject
    
    for(int i = 0; i < number; ++i) // перебираем студентов
    {
        if(students[i].Ratings[index] == 5)
        {
            MathExellent.push_back(students[i]);
        }
    }
    
    return MathExellent;
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
    
    vector<Student> students = {Freder, Katty, Andrey};
    

    vector<Student> MathExellent = VectorMathExellent(students);
    
    for (int i = 0; i < MathExellent.size(); ++i)
    {
        cout << MathExellent[i].Name << endl;
    }
    return 0;
}
