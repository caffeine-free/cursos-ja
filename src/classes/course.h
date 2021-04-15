#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Course {
public:
    virtual ~Course() {};

    virtual string getName() const = 0;

    virtual void setName(const string&) = 0;

    virtual string getDescription() const = 0;

    virtual void setDescription(const string&) = 0;

    virtual string getPrice() const = 0;

    virtual void setPrice(const string&) = 0;
};

#endif // COURSE_H
