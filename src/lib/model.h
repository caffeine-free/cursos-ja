#ifndef MODEL_H
#define MODEL_H

#include "../classes/course.h"

class Model {
public:
    virtual ~Model() {};

    static Model* createModel();

    virtual Course* createCourse(string, string, string) = 0;

    virtual vector<Course*>& getCourses() = 0;

    virtual void setCourses(const vector<Course*> &) = 0;

    virtual void add(Course*);
};

#endif // MODEL_H
