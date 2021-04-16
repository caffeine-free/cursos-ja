#include <QtTest>
#include "../../../cursos-ja/src/classes/user_impl.cpp"
#include "../../../cursos-ja/src/classes/user.h"
#include "../../../cursos-ja/src/classes/course_impl.cpp"
#include "../../../cursos-ja/src/classes/course.h"
#include "../../../cursos-ja/src/lib/model_impl.cpp"
#include "../../../cursos-ja/src/lib/model.h"
#include <vector>

class testCursosJa : public QObject
{
    Q_OBJECT

public:
    testCursosJa();
    ~testCursosJa();

private slots:
    void unit_user_constructor();
    void unit_user_operator();
    void unit_user_copyTest();
    void unit_user_assignTest();
    void unit_user_comparison();
    void unit_comment_constructor();
    void unit_comment_operator();
    void unit_comment_copyTest();
    void unit_comment_assignTest();
    void unit_serie_constructor();
    void unit_serie_operator();
    void unit_serie_copyTest();
    void unit_serie_assignTest();
    void unit_register_constructor();
    void unit_register_assignTest();
    void unit_model_constructor();
    void unit_model_assignTest();
};

testCursosJa::testCursosJa(){}

testCursosJa::~testCursosJa(){}

void testCursosJa::unit_user_constructor()
{
    User* user1 = new UserImpl();

    QVERIFY(user1->getName() == "");
    QVERIFY(user1->getEmail() == "");
    QVERIFY(user1->getCPF() == "");
    QVERIFY(user1->getPassword() == "");
    QVERIFY(user1->getCourses().empty() == true);
    delete user1;
}

void testCursosJa::unit_user_operator()
{
    User *s1 = new UserImpl();
    s1->setName("Mary");

    User* s2 = new UserImpl();
    (*s2) = (*s1);

    QVERIFY(s1 != s2 && s1->getName() == s2->getName());
    delete s1;
    delete s2;
}

void testCursosJa::unit_user_copyTest()
{
    User *s1 = new UserImpl();
    s1->setName("Mary");

    User* s2 = new UserImpl(s1);

    QVERIFY(s1 != s2 && s1->getName() == s2->getName());
    delete s1; delete s2;
}

// to-do: include test
void testCursosJa::unit_user_assignTest()
{
    User *s1 = new UserImpl();
    vector<bool> v;
    s1->setName("Mary");
    s1->setEmail("mary@gmail.com");
    s1->setCPF("145.941.222-22");
    s1->setPassword("1234");
    QVERIFY(s1->getName() == "Richard");
    QVERIFY(s1->getEmail() == "richard@gmail.com");
    QVERIFY(s1->getCPF() == "145.941.222-22");
    QVERIFY(s1->getPassword() == "1234");
    delete s1;
}

void testCursosJa::unit_user_comparison(){
    User *s1 = new UserImpl();
    vector<bool> v;
    s1->setName("Richard");
    s1->setEmail("richard@gmail.com");
    s1->setCPF("145.941.222-22");
    s1->setPassword("1234");

    User *s2 = new UserImpl();
    s2->setName("Richard");
    s2->setEmail("richard@gmail.com");
    s2->setCPF("145.941.222-22");
    s2->setPassword("1234");

    QCOMPARE (s1->getName(), s2->getName());
    QCOMPARE (s1->getEmail(), s2->getEmail());
    QCOMPARE (s1->getCPF(), s2->getCPF());
    QCOMPARE (s1->getPassword(), s2->getPassword());

    delete s1;
    delete s2;
}

/*
QTEST_MAIN(testCursosJa)
#include "tst_testseriesfeelings.moc
*/
