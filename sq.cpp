#include <sq.h>

sq::sq(int x,int y,bool mine,QImage* image,QImage* _g_image)
    :_x(x),_y(y),_mine(mine),around_num(0),swped(0),g_image(_g_image)
{
    parent = new QWidget(0);
    result = new QLabel(parent);
    button = new QPushButton(parent);
    flag = new QLabel(parent);
    flag->setPixmap(QPixmap::fromImage(image->scaled(QSize(30,30))));
    flag->hide();

    button ->setFocusPolicy(Qt::NoFocus);;

    parent->installEventFilter(this);
    button->installEventFilter(this);

    left_pressed=right_pressed=false;
}
bool sq::eventFilter(QObject *obj,QEvent *event)
{
    if(obj != parent && obj != button ) return QObject::eventFilter(obj,event);

    if(event->type() == QEvent::MouseButtonPress)
    {
        if(static_cast<QMouseEvent*>(event) ->buttons() == (Qt::LeftButton|Qt::RightButton))
            emit sweep_pre();
         switch( static_cast<QMouseEvent*>(event) ->button() )
         {
            case Qt::LeftButton : { left_pressed=true; break;}
            case Qt::RightButton :{right_pressed=true; return true;}
            default: {}
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
                        emit sweep_all();
                    break;
                }
            case Qt::RightButton :
                {
                    right_pressed=false;
                    if(left_pressed)
                        emit sweep_all();
                    else
                    {
                        if(!swped)
                            flag->setVisible(flag->isHidden());
                    }
                    return true;
                    break;
                }
            default: {}
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

    result->resize(27,27);
    button->resize(27,27);
    flag->resize(27,27);
}

void sq::sweep()
{
	flag->setPixmap(QPixmap::fromImage(g_image->scaled(QSize(30,30))));
    button->hide();
    swped=true;
}



