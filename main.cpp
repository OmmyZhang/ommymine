#include "setting.h"
#include "body.h"
#include "setmap.h"
#include "result.h"

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    
    SetMap* sm = new SetMap();
    sm->start();

    return app.exec();
}

