#include "src/lib/model_impl.h"
#include "src/classes/user_impl.h"
#include "src/classes/course_impl.h"

bool update_user_unit_test(){
    Model* model = new ModelImpl();

    vector<Course*> client_courses;
    client_courses.push_back(new CourseImpl());
    User* user = new UserImpl("maria", "maria@gmail.com", "2", "3", client_courses, 0);

    string name= "João";
    string email= "joao@gmail.com";
    string cpf= "4";
    string password= "5";

    model->updateUser(user, name, email, cpf, password);

    delete model;
    delete user;
}

bool remove_user_unit_test(){
    Model* model = new ModelImpl();

    vector<Course*> client_courses;
    client_courses.push_back(new CourseImpl());
    User* user = new UserImpl("maria", "maria@gmail.com", "2", "3", client_courses, 0);
    model->removeUser(user);
    // printar size do users
    cout << "O cliente foi removido";

    delete model;
    delete user;
}
