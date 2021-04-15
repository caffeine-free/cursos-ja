#ifndef COURSE_IMPL_H
#define COURSE_IMPL_H

#include "course.h"

using namespace std;

class CourseImpl : public Course {
protected:
    string name;
    string description;
    string price;
public:
    CourseImpl();

    CourseImpl(Course*);

    CourseImpl(string, string, string);

    ~CourseImpl();

    string getName() const;

    void setName(const string&);

    string getDescription() const;

    void setDescription(const string&);

    string getPrice() const;

    void setPrice(const string&);
};

#endif // COURSE_IMPL_H
