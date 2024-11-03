#include <iostream>
#include <vector>

using namespace std;
struct Student{
    string Name;
    string GroupId;
    vector<unsigned> Ratings;
    vector<string> Subject;

};


size_t CountTwoness(const vector<Student>&students)
{
    size_t count = 0;
    unsigned long number;
    number = students.size(); // количество студентов
    
    for(int i = 0; i < number; ++i) // перебираем студентов
    {
        for(int rat_num = 0; rat_num < students[i].Ratings.size(); ++rat_num) // перебираем их оценки
        {
            if(students[i].Ratings[rat_num] < 3)
            {
                count += 1;
                break;
            }
        }
    }
    
    return count; // количество студентов с неудовлетворительными оценками
}

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

