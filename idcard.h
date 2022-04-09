#ifndef IDCARD_H
#define IDCARD_H

#include "Sdtapi.h"

class IDCard
{
public:
    IDCard();
    ~IDCard();
    bool readCard(char * Name, char * Gender, char * Folk,
                  char *BirthDay, char * Code, char * Address,
                  char *Agency, char * ExpireStart,char* ExpireEnd,char * directory);

private:
    int retjinglun;
    int iPort=1001;
    int isCard,cardType;
};

#endif // IDCARD_H
