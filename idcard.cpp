#include "idcard.h"
#include <QMessageBox>
#include <QString>
#include <QObject>
#include <QDebug>

IDCard::IDCard(char * Name, char * Gender, char * Folk,
               char *BirthDay, char * Code, char * Address,char *Agency, char * ExpireStart,char* ExpireEnd)
{
    int ret;
    int iPort=1001;
    int isCard,cardType;

    ret=InitComm(iPort);
    if (ret){
        isCard=Authenticate();
        if(isCard)
        {
            cardType=Routon_DecideIDCardType();
            if(cardType==100)
            {
                ReadBaseInfos( Name,  Gender, Folk,
                 BirthDay,  Code, Address,Agency,  ExpireStart, ExpireEnd);
                  qDebug()<<"测试"<<QString::fromLocal8Bit(Name) <<QString::fromLocal8Bit(Gender);
            }
        }
        else
        {
            QMessageBox::information(NULL, ("提示"),("身份证读取失败，找不到身份证，请将身份证放到读卡器上!"));
        }
    }
    else
    {
        QMessageBox::information(NULL, ("提示"),("初始化身份证读卡器失败！ "));
    }

    CloseComm();
}

IDCard::~IDCard()
{

}
