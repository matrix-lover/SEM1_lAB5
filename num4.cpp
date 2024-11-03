#include <iostream>
#include <vector>

using namespace std;
struct Student{
    string Name;
    string GroupId;
    vector<unsigned> Ratings;
    vector<string> Subject;

};

size_t CountExellent(const vector<Student>&students)
{
    size_t count = 0;
    unsigned long number;
    number = students.size();
    
    for(int i = 0; i < number; ++i)
    {
        for(int rat_num = 0; rat_num < students[i].Ratings.size(); ++rat_num) // перебираем оценки
        {
            if(students[i].Ratings[rat_num] != 5) // какая - то из оценок не 5
            {
                count += 1;
                break; // чтобы не считать все оценки, не равные 5
            }
        }
    }
    
    return number - count; // все - неотличники
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
    Andrey.Ratings = {4, 5, 5, 5};
    Katty.Ratings = {5, 5, 5, 5};
    
    vector<Student> students = {Freder, Katty, Andrey};
    

    size_t count = CountExellent(students);
    
    cout << count << endl;
    return 0;
}
