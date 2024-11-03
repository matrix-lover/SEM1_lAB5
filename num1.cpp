// !! студента с меньшим индексом будем называть верхним, а с большим индексом - нижним(как в воображаемом журнале)
#include <iostream>
#include <vector>

using namespace std;
struct Student{
    string Name;
    string GroupId;
    vector<unsigned> Ratings;
    vector<string> Subject;
};

void SortByName(vector<Student>&students)
{
    unsigned long number;
    number = students.size(); // количество студентов
    Student Ghost; // ненастоящий студент для обмена местами двух действительных студентов
    for(int i = 0; i < number; ++i) // перебираем каждого студента
    {
        for(int j = i; j < number; ++j) // перебираем для данного студента пару, с которой он не сравнивался (в каждой итерации индекс j >= i ==> по условию(строка 6) i-тый студент всегда будет верхним по отношению к j-тому)
        {
            if(int(students[j].Name[0]) < int(students[i].Name[0])) // если первая буква имени верхнего студента по алфавиту идет после буквы имени нижнего студента
                // int("A") = 65 int("Z") = 95, строчные буквы кодируются в таком же порядке, но в случае с именами они не нужны int("a") = 97 int("z") = 122
            {
                Ghost = students[i];
                students[i] = students[j]; // меняем
                students[j] = Ghost;
            }
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
    vector<Student> students = {Freder, Katty, Andrey};
    
    SortByName(students);
    
    cout << students[0].Name << " " << students[1].Name << " "<< students[2].Name << endl;
    return 0;
}
