#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>     //ostream_iterator
#include <functional>   //not2



using namespace std;

class student
{
public:
    string name;
    unsigned int score;

    student(const string& n, unsigned int s) :
        name(n), score(s)
    {}

    friend ostream& operator<<(ostream& os, const student& rhs)
    {
        return os << rhs.score << " : " << rhs.name << endl;
    }
};


class comp : public unary_function <student,bool>  //unary_function 是用于使用一个参数创建函数对象的基类。unary_function 没有定义 operator(); 预期派生类将对此进行定义。
{
public:
    bool operator()(const student& stu) const
    {
        return stu.score >= 60;
    }
};

int main()
{
    student stu[] = {
            student("aa", 100),
            student("bb", 95),
            student("cc", 50),
            student("dd", 40),
            student("ee", 52),
            student("ff", 60),
            student("gg", 86),
            student("hh", 60),
            student("ii", 83),
            student("jj", 91),
    };
    vector<student> stuArray(stu, stu + sizeof(stu) / sizeof(student));
    vector<student>::iterator it = partition(stuArray.begin(), stuArray.end(), comp());
    vector<student>::iterator i;
    for (i = stuArray.begin(); i < it; i++) {
        cout << (*i).name << " : " << (*i).score << endl;
    }
    //copy(stuArray.begin(), it, ostream_iterator<student>(cout, ""));	//输出分数大于60分的人
    cout << "=======" << endl;
    for (i = it; i < stuArray.end(); i++) {
        cout << (*i).name << " : " << (*i).score << endl;
    }
    //copy(it, stuArray.end(), ostream_iterator<student>(cout, ""));	//输出分数小于等于60分的人
    return 0;
}


#if 0
struct student
{
    string name;
    unsigned int score;

    student(const string& n, unsigned int s) :
        name(n), score(s)
    {}

    friend ostream& operator<<(ostream& os, const student& rhs)
    {
        return os << rhs.score << " : " << rhs.name << endl;
    }
};


struct comp : public unary_function<student, bool> //unary_function 是用于使用一个参数创建函数对象的基类。unary_function 没有定义 operator(); 预期派生类将对此进行定义。
{
    bool operator()(const student& stu) const
    {
        return stu.score >= 60;
    }
};

int main()
{
    student stu[] = {
            student("aa", 100),
            student("bb", 95),
            student("cc", 50),
            student("dd", 40),
            student("ee", 52),
            student("ff", 60),
            student("gg", 86),
            student("hh", 60),
            student("ii", 83),
            student("jj", 91),
    };
    vector<student> stuArray(stu, stu + sizeof(stu) / sizeof(student));
    vector<student>::iterator it = partition(stuArray.begin(), stuArray.end(), comp());
    copy(stuArray.begin(), it, ostream_iterator<student>(cout, ""));	//输出分数大于60分的人
    cout << "=======" << endl;
    copy(it, stuArray.end(), ostream_iterator<student>(cout, ""));	//输出分数小于等于60分的人
    return 0;
}

#endif