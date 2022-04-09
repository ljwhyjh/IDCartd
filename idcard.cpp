#include "idcard.h"
#include <QMessageBox>
#include <QString>
#include <QObject>
#include <QDebug>

IDCard::IDCard()
{
   iPort=1001;

   retjinglun=InitComm(iPort);

}

IDCard::~IDCard()
{
    CloseComm();
}

bool IDCard::readCard(char *Name, char *Gender, char *Folk, char *BirthDay, char *Code, char *Address, char *Agency, char *ExpireStart,
                      char *ExpireEnd,char * directory)
{
    if (retjinglun){
        isCard=Authenticate();
        if(isCard)
        {
            cardType=Routon_DecideIDCardType();
            if(cardType==100)
            {
                ReadBaseInfos( Name,  Gender, Folk,
                 BirthDay,  Code, Address,Agency,  ExpireStart, ExpireEnd);
            }
        }
        else
        {
            QMessageBox::information(NULL, ("提示"),("身份证读取失败，找不到身份证，请将身份证放到读卡器上!"));
            return  false;
        }
    }
    else
    {
        QMessageBox::information(NULL, ("提示"),("初始化身份证读卡器失败！ "));
        return  false;
    }

    return true;
}
