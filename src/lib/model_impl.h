#ifndef MODEL_IMPL_H
#define MODEL_IMPL_H

#include "model.h"
#include "../classes/course_impl.h"

using namespace std;

class ModelImpl : public Model {
protected:
    vector<Course*> courses;

public:
    ModelImpl();

    ~ModelImpl();

    static Model* createModel();

    Course* createCourse(string, string, string);

    vector<Course*>& getCourses();

    void setCourses(const vector<Course*> &);

    void add(Course*);
};

#endif // MODEL_IMPL_H
