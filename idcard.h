#ifndef IDCARD_H
#define IDCARD_H

#include "Sdtapi.h"

class IDCard
{
public:
    IDCard(char * Name, char * Gender, char * Folk,
           char *BirthDay, char * Code, char * Address,char *Agency, char * ExpireStart,char* ExpireEnd);
    ~IDCard();
};

#endif // IDCARD_H
