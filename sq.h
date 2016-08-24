#ifndef _SQ_H_
#define _SQ_H_
#include <setting.h>

class sq : public QObject 
{
    Q_OBJECT
 
    public:
        sq(int,int,bool,QImage*);
        ~sq() { delete parent;}
        void update();
        
        int _x,_y;
        bool _mine;
        int around_num;
        bool swped;

        QGroupBox* parent;
        QLabel* result,*flag;
        QPushButton* button; 
        
        void sweep();

        bool eventFilter(QObject*,QEvent*);
};
#endif