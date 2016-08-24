#ifndef _RESULT_H_
#define _RESULT_H_

#include "setting.h"
class Result : public QDialog
{
    Q_OBJECT

    private:
        QLabel *text;
        QGridLayout *Layout;
        QWidget *win;
    public:
        Result();
        QPushButton *again_button,*exit_button;
    public slots:
        void _run(int);

};

#endif
