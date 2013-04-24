#ifndef DATASTRUCT_H
#define DATASTRUCT_H

#include <QString>
#include <QList>

struct Student {
    QString student_id;
    QString first_name;
    QString middle_name;
    QString last_name;
    float point;
};

struct RoomList {
    QString subject_name;
    QString subject_id;
    QList<Student> students;
};

#endif // DATASTRUCT_H
