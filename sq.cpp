#include <sq.h>

sq::sq(int x,int y,bool mine,QImage* image)
    :_x(x),_y(y),_mine(mine),around_num(0),swped(0)
{
    parent = new QGroupBox(0);
    result = new QLabel(parent);
    button = new QPushButton(parent);
    flag = new QLabel(parent);
    flag->setPixmap(QPixmap::fromImage(image->scaled(QSize(30,30))));
    flag->hide();

    parent->installEventFilter(this);
    button->installEventFilter(this);

    left_pressed=right_pressed=false;
}
bool sq::eventFilter(QObject *obj,QEvent *event)
{
    if(obj != parent && obj != button ) return QObject::eventFilter(obj,event);

    if(event->type() == QEvent::MouseButtonPress)
    {
         switch( static_cast<QMouseEvent*>(event) ->button() )
         {
             case Qt::LeftButton : { left_pressed=true; break;}
             case Qt::RightButton :{right_pressed=true; return true;}
        }
    }
    else 
    if(event->type() == QEvent::MouseButtonRelease)
    {
        switch( static_cast<QMouseEvent *>(event) ->button() )
        {
            case Qt::LeftButton :
                {
                    left_pressed=false;
                    if(right_pressed)
                        puts("L+R");
                    break;
                }
            case Qt::RightButton :
                {
                    right_pressed=false;
                    if(left_pressed)
                        puts("R+L");
                    else
                    {
                        if(!swped)
                            flag->setVisible(flag->isHidden());
                    }
                    return true;
                    break;
                }
        }
    }
    
    return false;
}
void sq::update()
{
    if(!_mine)
    {
        if(around_num)
            result->setNum(around_num);
        result->setStyleSheet("color:green;");
    }
    else
    {
        result->setText("X");
        result->setStyleSheet("color:red;");
    }

    result->setFont(QFont("Timers", 17, QFont::Bold));
    result->setAlignment(Qt::AlignCenter); 

    result->resize(28,28);
    button->resize(28,28);
    flag->resize(28,28);
}

void sq::sweep()
{
    button->hide();
    swped=true;
}



