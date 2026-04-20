#ifndef PROFILE_H
#define PROFILE_H

#include <QString>

class Profile
{
    
public:
    QString firstName;
    QString lastName;
    QString birthday_day;
    QString birthday_month;
    QString birthday_year;
    QString gender;
    QString username;
    QString password;
    QString profileImagePath;
    int bestScore;
    
    Profile();
};

#endif // PROFILE_H
