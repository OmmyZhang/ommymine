#include "setmap.h"

SetMap::SetMap()
{
    ok = new QPushButton("OK");
    re = new QPushButton("Reset");

    get_n = new QLineEdit;
    get_m = new QLineEdit;

    l_n = new QLabel("How many rows?       (3~20):");
    l_m = new QLabel("How many columns?(3~20):");

    get_dif = new QLabel("15");
    l_dif = new QLabel("How many mines?(10% ~ 70%): ");
    l_dif2 = new QLabel("% ");
    scroll_dif = new QScrollBar;

    scroll_dif->setValue(15);

    get_n->setValidator(new QIntValidator(1,MAXN-1,this));
    get_m->setValidator(new QIntValidator(1,MAXM-1,this));


    CON(scroll_dif,SIGNAL(valueChanged(int)),get_dif,SLOT(setNum(int)));

    CON(ok,SIGNAL(clicked()),this,SLOT(check()));
    CON(re,SIGNAL(clicked()),this,SLOT(reset()));

    QHBoxLayout *ButtonLayout = new QHBoxLayout;
    ButtonLayout->addWidget(ok);
    ButtonLayout->addWidget(re);

    QHBoxLayout *Input1Layout = new QHBoxLayout,
                *Input2Layout = new QHBoxLayout,
                *Input3Layout = new QHBoxLayout;
                
    Input1Layout->addWidget(l_n);
    Input1Layout->addWidget(get_n);
    Input2Layout->addWidget(l_m);
    Input2Layout->addWidget(get_m);
    Input3Layout->addWidget(l_dif);
    Input3Layout->addWidget(get_dif);
    Input3Layout->addWidget(l_dif2);
    Input3Layout->addWidget(scroll_dif);

    QVBoxLayout *MainLayout = new QVBoxLayout;
    MainLayout->addLayout(Input1Layout);
    MainLayout->addLayout(Input2Layout);
    MainLayout->addLayout(Input3Layout);
    MainLayout->addLayout(ButtonLayout);

    setLayout(MainLayout);

    resize(250,300);

}

void SetMap::start()
{
    show();
}
void SetMap::restart()
{
	delete mainbody;
	delete last;
	start();
}
void SetMap::quit()
{
	delete mainbody;
	delete last;
	close();
}
void SetMap::reset()
{
    get_n->clear();
    get_m->clear();
    scroll_dif->setValue(15);
}
void SetMap::check()
{
    n = get_n->text().toInt();
    m = get_m->text().toInt();
    dif = scroll_dif->value();

    if(n>=3 && m>=3 && dif>=10 && dif<=70)
    {
        hide();
        mainbody =  new Body;
        last = new Result(); 
        CON(mainbody,SIGNAL(end(int)),last,SLOT(_run(int)));
        CON(last->again_button,SIGNAL(clicked()),this,SLOT(restart()));
        CON(last-> exit_button,SIGNAL(clicked()),this,SLOT(quit()
        ));
        mainbody->play(n,m,dif);
    }
    else
        reset();
}








