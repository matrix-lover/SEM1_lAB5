#include <iostream>
#include <vector>

using namespace std;
struct Student{
    string Name;
    string GroupId;
    vector<unsigned> Ratings;
    vector<string> Subject;
};


void SortByRating(vector<Student>&students)
{
    float arif_mean_i = 0;
    float arif_mean_j = 0;
    unsigned long number;
    number = students.size(); // количество студентов
    Student Ghost; // ненастоящий студент для обмена местами двух действительных студентов
    
    for(int i = 0; i < number; ++i)// перебираем каждого студента
    {
        for( int j = i; j < number; ++j)// перебираем для данного студента пару, с которой он не сравнивался (в каждой итерации индекс j >= i ==> по условию(строка 6) i-тый студент всегда будет верхним по отношению к j-тому)
        {
            for(int rat_num = 0; rat_num < students[i].Ratings.size(); ++rat_num) // сумма оценок верхнего студента
            {
                arif_mean_i += students[i].Ratings[rat_num];
            }
            arif_mean_i = arif_mean_i / float(students[i].Ratings.size()); // средняя оценка верхнего студента
            
            for(int rat_num = 0; rat_num < students[j].Ratings.size(); ++rat_num) // сумма оценок нижнего студента
            {
                arif_mean_j += students[j].Ratings[rat_num];
            }
            arif_mean_j = arif_mean_j / float(students[j].Ratings.size()); // средняя оценка нижнего студента
            
            if(arif_mean_i < arif_mean_j) // если средняя оценка верхнего студента ниже, чем у нижнего
            {
                Ghost = students[i];
                students[i] = students[j]; // меняем
                students[j] = Ghost;
            }
            arif_mean_i = 0; // обнуляем
            arif_mean_j = 0;
        }
    }
    
}

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
    
    vector<Student> students = {Freder, Andrey, Katty};
    
    SortByRating(students);
    
    int i = 1;
    for(const Student& student : students)
    {
        cout << i << ": " << student.Name << endl;
        i += 1;
    }
    return 0;
}
