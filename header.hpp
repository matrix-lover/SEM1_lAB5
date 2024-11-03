// void SortByName(vector<Student>&students);
// void SortByRating(vector<Student>&students);
// size_t CountTwoness(const vector<Student>&students);
// size_t CountExellent(const vector<Student>&students);
// vector<Student> VectorMathExellent(const vector<Student>&students);
// vector<string> GroupsId(const vector<Student>&students);

#include <iostream>
#include <vector>

using namespace std;

// !! студента с меньшим индексом буду называть верхним, а с большим индексом - нижним(как в воображаемом журнале)

void SortByName(vector<Student>&students)
{
    unsigned long number;
    number = students.size(); // количество студентов
    Student Ghost; // ненастоящий студент для обмена местами двух действительных студентов
    for(int i = 0; i < number; ++i) // перебираем каждого студента
    {
        for(int j = i; j < number; ++j) // перебираем для данного студента пару, с которой он не сравнивался (в каждой итерации индекс j >= i ==> по условию(строка 13) i-тый студент всегда будет верхним по отношению к j-тому)
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


void SortByRating(vector<Student>&students)
{
    float arif_mean_i = 0;
    float arif_mean_j = 0;
    unsigned long number;
    number = students.size(); // количество студентов
    Student Ghost; // ненастоящий студент для обмена местами двух действительных студентов
    
    for(int i = 0; i < number; ++i)// перебираем каждого студента
    {
        for( int j = i; j < number; ++j)// перебираем для данного студента пару, с которой он не сравнивался (в каждой итерации индекс j >= i ==> по условию(строка 13) i-тый студент всегда будет верхним по отношению к j-тому)
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

vector<string> GroupsId(const vector<Student>&students)
{
    vector<string> Groups;
    unsigned long number;
    number = students.size(); // количество студентов
    int index = 0; // индекс предмета в векторе Subject
    
    for(int i = 0; i < number; ++i) // перебираем студентов
    {
        
    }
    
    return Groups;
}


vector<string> GroupsId(const vector<Student>&students)
{
    vector<string> Groups;
    unsigned long number;
    number = students.size(); // количество студентов
    int count = 0;
    
    for(int i = 0; i < number; ++i) // перебираем студентов
    {
        for(int j = 0; j < Groups.size(); ++j) // перебираем названия групп, уже записанных в Groups
        {
            if(students[i].GroupId == Groups[j]) // если уже есть группа с таким же названием в массиве Groups
            {
                count += 1;
            }
        }
        if(count != 1) // если нет таких
        {
            Groups.push_back(students[i].GroupId);
        }
        count = 0;
    }
    
    return Groups;
}

