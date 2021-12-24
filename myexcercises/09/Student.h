#ifndef GUARD_student_h
#define GUARD_student_h

#include <string>
#include <vector>
#include <iostream>

class Student
{
    private:
        std::string m_name;
        double m_fgrade;
        double m_midterm;
        std::vector<double> m_homework;
        double m_final;
        int m_total_ops;

    public:
        
        // constructors and destructors
        Student():
            m_fgrade(NULL), m_midterm(NULL), m_final(NULL), m_total_ops(1) {};
        Student(std::istream&);
        Student(const Student&);
        ~Student();

        // methods
        std::istream &read(std::istream&);
        double grade() const;
        // tells the user whether the object contains valid data
        bool valid() const { return !(this->m_homework.empty()); };

        // getters
        std::string name() const { return this->m_name; };

        // setters
        void read_hw(std::istream&);
};

#endif
