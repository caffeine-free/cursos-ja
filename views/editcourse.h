#ifndef EDITCOURSE_H
#define EDITCOURSE_H

#include <QDialog>
#include "../cursos-ja/src/classes/course.h"
#include "../cursos-ja/src/lib/model.h"

namespace Ui {
class EditCourse;
}

/**
 * @brief This class represents the page to edit the course's values
 * 
 */
class EditCourse : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Construct a new Edit Course object
     * 
     * @param parent 
     */
    explicit EditCourse(QWidget *parent = nullptr);

    /**
     * @brief Destroy the Edit Course object
     * 
     */
    ~EditCourse();

    /**
     * @brief Get the Course object
     * 
     * @return Course* the Course to be updated
     */
    Course *getCourse() const;

    /**
     * @brief Set the Course object
     * 
     * @param value the new Course to be updated
     */
    void setCourse(Course *value);

    /**
     * @brief Get the Model object
     * 
     * @return Model* the Edit Course's model
     */
    Model *getModel() const;

    /**
     * @brief Set the Model object
     * 
     * @param value the Edit Course's new model
     */
    void setModel(Model *value);

private slots:
    /**
     * @brief function to updated the course's values
     * 
     */
    void on_edit_btn_clicked();

    /**
     * @brief function to cancel the update
     * 
     */
    void on_CANCEL_clicked();

private:
    Ui::EditCourse *ui; // The EditCourse's ui
    Model* model; // The Edit Course's model
    Course* course; // The Edit Course's course
};

#endif // EDITCOURSE_H
