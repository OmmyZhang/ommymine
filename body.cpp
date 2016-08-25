#include "body.h"
#include <ctime>
void Body::play(int nn,int mm,int dif)
{
    n=nn;m=mm;
    rest=n*m;;
    srand(clock());
  
    show();
    setMinimumSize(m*33+20,n*33+48);
    resize(m*33+20,n*33+48);

    setWindowTitle(QObject::tr(" +1s ! "));

    MainLayout = new QVBoxLayout;
    Layout = new QGridLayout;
    Smapper = new QSignalMapper(this);

    l_life= new QLabel;
    l_life->setFixedSize(140,25);

    MainLayout -> addWidget(l_life);

    bool rand_tmp;
    
    image = new QImage("wa.png");
    g_image = new QImage("wa_g.png");

    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
        {
            map[i][j] = new sq(i,j,rand_tmp=(rand()%100 < dif),image,g_image);
            rest-=rand_tmp;           
            Layout->addWidget(map[i][j]->parent,i,j);
            
            CON(map[i][j]->button,SIGNAL(clicked()),Smapper,SLOT(map()));
            
            Smapper->setMapping(map[i][j]->button,i*m+j);
        } 

    life = (m*n-rest) / 10 + 1;
    second=0;
    update_life();

    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
        {
            for(int ii=(i?i-1:0);ii<=i+1&&ii<n;++ii)
                for(int jj=(j?j-1:0);jj<=j+1&&jj<m;++jj)
                    map[i][j]->around_num += map[ii][jj]->_mine;
            map[i][j]->update();
        }


    MainLayout -> addLayout(Layout);
    setLayout(MainLayout);
        
    CON(Smapper,SIGNAL(mapped(int)),this,SLOT(sweep_xy(int)));
}
void Body::update_life()
{
	l_life->setText(QString::number(life,10)+QString(" life(s) ")+QString::number(second,10)+QString(" second(s)"));
}

void Body::sweep_xy(int xy)
{
    int i = xy / m;
    int j = xy % m;

	map[i][j] -> sweep();
    if( map[i][j] -> _mine)
    {
        --life;
        update_life();
        if(life == 0)   
            pre_end(1);
        else
        {
            QMessageBox *message = new QMessageBox(QMessageBox::NoIcon,"BOOM!    ( -1 life )","");
            //message->setIconPixmap(QPixmap("boom"));
            
            QMovie *movie = new QMovie("boom.gif");
            movie->setScaledSize(QSize(200,120));
            movie->start();

            QLabel *playmovie = new QLabel(message);
            playmovie->setMovie(movie);
            
            QGridLayout *tmp= (QGridLayout*)
            message->layout();
            tmp->addWidget(playmovie,0,0,1,2);
            message->setButtonText(QMessageBox::Ok,QString("Continue"));
            message->exec();
        }
            
    }
    else
    {
        if(--rest == 0)
            pre_end(0);
        ++second;
        if(second>=60)
            second-=60,life++;
        update_life();
    }

    if(!map[i][j] -> around_num)
    {
        for(int ii=(i?i-1:0);ii<=i+1&&ii<n;++ii)
            for(int jj=(j?j-1:0);jj<=j+1&&jj<m;++jj)
                if(!map[ii][jj]->swped && !map[ii][jj]->_mine)
                    sweep_xy(ii*m+jj);
    }
}
void Body::pre_end(int x)
{
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(!map[i][j]->_mine)
                map[i][j]->flag->setPixmap(QPixmap::fromImage(g_image->scaled(QSize(30,30))));
            else
                if(map[i][j]->flag->isHidden())
                    map[i][j]->button->hide();

	DISCON(Smapper,SIGNAL(mapped(int)),this,SLOT(sweep_xy(int)));
	emit end(x);
}

Body::~Body()
{
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			delete map[i][j];
 //   delete Layout;

}
