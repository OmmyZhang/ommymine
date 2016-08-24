#include "result.h"

Result::Result()
{
    text = new QLabel(this);
    
    again_button = new QPushButton("Play agin");
    exit_button  = new QPushButton("Quit");
}
void Result::_run(int x)
{
    Layout = new QGridLayout;

    Layout->addWidget(text,0,0,2,2);
    Layout->addWidget(again_button,2,0);
    Layout->addWidget(exit_button,2,1);

    setLayout(Layout);

    resize(250,200);
    if(x==0)
    {
        setWindowTitle(QObject::tr("Win!"));
        text->setText("Congratulation!");
        text->setStyleSheet("color:red;");
        text->setFont(QFont("Timers", 20, QFont::Bold));
    }
    else
    {
        setWindowTitle(QObject::tr("Failed!"));
        QMovie *qq;
    	if(x==-1)
    		qq = new QMovie("boom.gif"); 
    	else 
    		qq = new QMovie("too_young.gif");
        text->setMovie(qq);
        qq->setScaledSize(QSize(220,150));
        qq->start();
        
    }
    show();
}


