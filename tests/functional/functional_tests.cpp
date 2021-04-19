#include "functional_tests.h"

void functional_tests() {
    Model* model = Model::createModel();

    Course* course_1 = model->createCourse("New Course", "Course Description", "10,00");

    model->add(course_1);

    model->updateCourse(course_1, "Engenharia de Software I", "Engenharia de Software baseado na obra do autor Ian Sommerville", "129,00");

    vector<Course*> courses = model->getCourses();

    model->removeCourse(courses[0]);

    User* user_1 = model->createUser("New User", "user@email.com", "12345678909", "123", model->getCourses(), 0);

    model->addUser(user_1);

    model->updateUser(user_1, "Myllene", "myllene@email.com", "49053166750", "123");

    assert(course_1->getName() == "Engenharia de Software I");
    assert(model->getCourses().size() == 5);
    assert(model->getUserList().size() == 6);

    delete model;
}
