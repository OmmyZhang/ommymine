#ifndef _SQ_H_
#define _SQ_H_
#include <setting.h>

class sq : public QObject 
{
    Q_OBJECT
 
    public:
        sq(int,int,bool,QImage*,QImage*);
        ~sq() { delete parent;}
        void update();
        
        int _x,_y;
        bool _mine;
        int around_num;
        bool swped;
        bool left_pressed,right_pressed;

        QWidget* parent;
        QLabel* result,*flag;
        QPushButton* button; 
        QImage *g_image;
        
        void sweep();

        bool eventFilter(QObject*,QEvent*);
    signals:
        void sweep_all();
        void sweep_pre();
};
#endif
