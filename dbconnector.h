#ifndef DBCONNECTOR_H
#define DBCONNECTOR_H

#include "datastruct.h"

class DBConnector
{
public:
    DBConnector();
    RoomList get_room(QString id);
    void update_score(RoomList* room);
};

#endif // DBCONNECTOR_H
