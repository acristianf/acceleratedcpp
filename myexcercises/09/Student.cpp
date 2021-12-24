#include <vector>
#include <string>
#include <iostream>
#include "Student.h"
#include "grade.h"

using namespace std;

Student::Student(istream& in)
{
    this->m_total_ops = 1;
    this->read(in);
}

Student::Student(const Student& cpy)
{
    m_name = cpy.m_name;
    m_fgrade = cpy.m_fgrade;
    m_midterm = cpy.m_midterm;
    m_homework = cpy.m_homework;
    m_final = cpy.m_final;
    ++m_total_ops;
}

Student::~Student()
{
    ++m_total_ops;
    cout << "Total operations over object " << this << ": " << m_total_ops << endl;
}

void Student::read_hw(istream& in)
{
    double x;
    while (cin >> x)
    {
        this->m_homework.push_back(x);
    }
}

istream &Student::read(istream& in)
{
    cin >> this->m_name >> this->m_midterm >> this-> m_fgrade;
    this->read_hw(in);
    this->m_final = ::grade(this->m_midterm, this->m_fgrade, this->m_homework);
    return cin;
};

double Student::grade() const
{
    if (this->m_final != NULL)
    {
        return this->m_final;
    }
    else
    {
        return ::grade(this->m_midterm, this->m_fgrade, this->m_homework);
    }
};
