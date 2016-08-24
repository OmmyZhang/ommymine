#ifndef _SM_H_
#define _SM_H_

#include "setting.h"
#include "body.h"
#include "result.h"

class SetMap : public QDialog
{
    Q_OBJECT

    private:
        QPushButton *ok,*re;
        QLineEdit *get_m,*get_n;
        QLabel *l_m,*l_n,*l_dif,*l_dif2,*get_dif;
        QScrollBar *scroll_dif;
        int n,m,dif;
    
    public:
        SetMap();
        Body *mainbody;
        Result *last;
    
    public slots: 
        void start();
        void restart();
        void reset();
        void check();
        void quit();
};


#endif
