#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<candy.h>
#include<QLabel>
#include<time.h>
#include<QTime>
using namespace std;
candy candy[11][11];

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(start){
    int x,y,i,j,l,color,type,cho,chox,choy;
    bool twochoose;
    x=event->x();
    y=event->y();
    if(canmove==true){
        canmove=false;
    if(!choose){
        choose=true;
        for(i=100;i<551;i=i+50){
            for(j=0;j<451;j=j+50){
                if(x>j&&x<j+50&&y>i&&y<i+50){
                    candy[(x+50)/50][(y-50)/50].choose=true;
                }
            }
        }
        showcandy();
    }
    else{
        twochoose=false;
        l=0;
        for(i=100;i<551;i=i+50){
            for(j=0;j<451;j=j+50){
                if(x>j&&x<j+50&&y>i&&y<i+50){
                    candy[(x+50)/50][(y-50)/50].choose=true;
                }
            }
        }
        for(i=1;i<11;i++){
            for(j=1;j<11;j++){
                if(candy[i][j].choose){
                    l++;
                }
            }
        }
        if(l==2)
            twochoose=true;
        if(twochoose){
            for(i=1;i<11;i++){
                for(j=1;j<11;j++){
                    if(candy[i][j].choose&&candy[i+1][j].choose&&i<10){
                        if(candy[i][j].color==5){
                            cho=candy[i+1][j].color;
                            for(chox=1;chox<11;chox++){
                                for(choy=1;choy<11;choy++){
                                    if(candy[chox][choy].color==cho){
                                        candy[chox][choy].deleted=true;
                                    }
                                }
                            }
                            candy[i][j].deleted=true;
                            candy[i][j].choose=false;
                            candy[i+1][j].choose=false;
                            clearcandy();

                        }
                        else if(candy[i+1][j].color==5){
                            cho=candy[i][j].color;
                            for(chox=1;chox<11;chox++){
                                for(choy=1;choy<11;choy++){
                                    if(candy[chox][choy].color==cho){
                                        candy[chox][choy].deleted=true;
                                    }
                                }
                            }
                            candy[i+1][j].deleted=true;
                            candy[i][j].choose=false;
                            candy[i+1][j].choose=false;
                            clearcandy();

                        }
                        color=candy[i][j].color;
                        candy[i][j].color=candy[i+1][j].color;
                        candy[i+1][j].color=color;
                        type=candy[i][j].type;
                        candy[i][j].type=candy[i+1][j].type;
                        candy[i+1][j].type=type;
                        showcandy();
                        delay();
                        delay();
                        if(check()==0){
                            color=candy[i][j].color;
                            candy[i][j].color=candy[i+1][j].color;
                            candy[i+1][j].color=color;
                            type=candy[i][j].type;
                            candy[i][j].type=candy[i+1][j].type;
                            candy[i+1][j].type=type;
                            showcandy();
                            delay();
                            delay();
                        }
                    }
                    if(candy[i][j].choose&&candy[i][j+1].choose&&j<10){
                        if(candy[i][j].color==5){
                            cho=candy[i][j+1].color;
                            for(chox=1;chox<11;chox++){
                                for(choy=1;choy<11;choy++){
                                    if(candy[chox][choy].color==cho){
                                        candy[chox][choy].deleted=true;
                                    }
                                }
                            }
                            candy[i][j].deleted=true;
                            candy[i][j].choose=false;
                            candy[i][j+1].choose=false;
                            clearcandy();

                        }
                        else if(candy[i][j+1].color==5){
                            cho=candy[i][j].color;
                            for(chox=1;chox<11;chox++){
                                for(choy=1;choy<11;choy++){
                                    if(candy[chox][choy].color==cho){
                                        candy[chox][choy].deleted=true;
                                    }
                                }
                            }
                            candy[i][j+1].deleted=true;
                            candy[i][j].choose=false;
                            candy[i][j+1].choose=false;
                            clearcandy();

                        }
                        color=candy[i][j].color;
                        candy[i][j].color=candy[i][j+1].color;
                        candy[i][j+1].color=color;
                        type=candy[i][j].type;
                        candy[i][j].type=candy[i][j+1].type;
                        candy[i][j+1].type=type;
                        showcandy();
                        delay();
                        delay();
                        if(check()==0){
                            color=candy[i][j].color;
                            candy[i][j].color=candy[i][j+1].color;
                            candy[i][j+1].color=color;
                            type=candy[i][j].type;
                            candy[i][j].type=candy[i][j+1].type;
                            candy[i][j+1].type=type;
                            showcandy();
                            delay();
                            delay();
                        }
                    }
                }
            }
            choose=false;
            for(i=1;i<11;i++){
                for(j=1;j<11;j++){
                    candy[i][j].choose=false;
                }
            }
            showcandy();
            while(check()){
                clearcandy();

                step=step-1;
                QString st=QString::number(step);
                ui->step->setText(st);
                if(sco>35000){
                    gameover();
                }
                if(step==0){
                    gameover();
                }
                }
            }
        }

    canmove=true;
    }

    }
}

void MainWindow::showcandy(){
    int i,j;
    for(i=1;i<11;i++){
        for(j=1;j<11;j++){
            switch (candy[i][j].color) {
                case 0:b[i][j]->setPixmap(QPixmap(":/new/prefix1/nocandy.png"));break;
                case 1:switch(candy[i][j].choose){
                    case false:switch(candy[i][j].type){
                        case 0:b[i][j]->setPixmap(QPixmap(":/new/prefix1/blue.png"));break;
                        case 1:b[i][j]->setPixmap(QPixmap(":/new/prefix1/blue_row.png"));break;
                        case 2:b[i][j]->setPixmap(QPixmap(":/new/prefix1/blue_column.png"));break;
                        case 3:b[i][j]->setPixmap(QPixmap(":/new/prefix1/blue_bomb.png"));break;
                        default:break;
                    }break;
                    case true:switch(candy[i][j].type){
                        case 0:b[i][j]->setPixmap(QPixmap(":/new/prefix1/blue_choose.png"));break;
                        case 1:b[i][j]->setPixmap(QPixmap(":/new/prefix1/blue_row_choose.png"));break;
                        case 2:b[i][j]->setPixmap(QPixmap(":/new/prefix1/blue_column_choose.png"));break;
                        case 3:b[i][j]->setPixmap(QPixmap(":/new/prefix1/blue_bomb_choose.png"));break;
                        default:break;
                    }break;
                    default:break;
                    }break;
                case 2:switch(candy[i][j].choose){
                    case false:switch(candy[i][j].type){
                        case 0:b[i][j]->setPixmap(QPixmap(":/new/prefix1/green.png"));break;
                        case 1:b[i][j]->setPixmap(QPixmap(":/new/prefix1/green_row.png"));break;
                        case 2:b[i][j]->setPixmap(QPixmap(":/new/prefix1/green_column.png"));break;
                        case 3:b[i][j]->setPixmap(QPixmap(":/new/prefix1/green_bomb.png"));break;
                        default:break;
                    }break;
                    case true:switch(candy[i][j].type){
                        case 0:b[i][j]->setPixmap(QPixmap(":/new/prefix1/green_choose.png"));break;
                        case 1:b[i][j]->setPixmap(QPixmap(":/new/prefix1/green_row_choose.png"));break;
                        case 2:b[i][j]->setPixmap(QPixmap(":/new/prefix1/green_column_choose.png"));break;
                        case 3:b[i][j]->setPixmap(QPixmap(":/new/prefix1/green_bomb_choose.png"));break;
                        default:break;
                    }break;
                    default:break;
                    }break;
                case 3:switch(candy[i][j].choose){
                    case false:switch(candy[i][j].type){
                        case 0:b[i][j]->setPixmap(QPixmap(":/new/prefix1/red.png"));break;
                        case 1:b[i][j]->setPixmap(QPixmap(":/new/prefix1/red_row.png"));break;
                        case 2:b[i][j]->setPixmap(QPixmap(":/new/prefix1/red_column.png"));break;
                        case 3:b[i][j]->setPixmap(QPixmap(":/new/prefix1/red_bomb.png"));break;
                        default:break;
                    }break;
                    case true:switch(candy[i][j].type){
                        case 0:b[i][j]->setPixmap(QPixmap(":/new/prefix1/red_choose.png"));break;
                        case 1:b[i][j]->setPixmap(QPixmap(":/new/prefix1/red_row_choose.png"));break;
                        case 2:b[i][j]->setPixmap(QPixmap(":/new/prefix1/red_column_choose.png"));break;
                        case 3:b[i][j]->setPixmap(QPixmap(":/new/prefix1/red_bomb_choose.png"));break;
                        default:break;
                    }break;
                    default:break;
                    }break;
                case 4:switch(candy[i][j].choose){
                    case false:switch(candy[i][j].type){
                        case 0:b[i][j]->setPixmap(QPixmap(":/new/prefix1/yellow.png"));break;
                        case 1:b[i][j]->setPixmap(QPixmap(":/new/prefix1/yellow_row.png"));break;
                        case 2:b[i][j]->setPixmap(QPixmap(":/new/prefix1/yellow_column.png"));break;
                        case 3:b[i][j]->setPixmap(QPixmap(":/new/prefix1/yellow_bomb.png"));break;
                        default:break;
                    }break;
                    case true:switch(candy[i][j].type){
                        case 0:b[i][j]->setPixmap(QPixmap(":/new/prefix1/yellow_choose.png"));break;
                        case 1:b[i][j]->setPixmap(QPixmap(":/new/prefix1/yellow_row_choose.png"));break;
                        case 2:b[i][j]->setPixmap(QPixmap(":/new/prefix1/yellow_column_choose.png"));break;
                        case 3:b[i][j]->setPixmap(QPixmap(":/new/prefix1/yellow_bomb_choose.png"));break;
                        default:break;
                    }break;
                    default:break;
                    }break;
                case 5:switch(candy[i][j].choose){
                    case false:b[i][j]->setPixmap(QPixmap(":/new/prefix1/chocolate.png"));break;
                    case true:b[i][j]->setPixmap(QPixmap(":/new/prefix1/chocolate_choose.png"));break;
                    default:break;
                    }break;
                    default:break;
                }
        }
    }
}


int MainWindow::check(){
    int i,j;
    for(i=1;i<11;i++){
        for(j=1;j<11;j++){
            if(candy[i][j].deleted){
                return 1;
            }
            if(i<9&&candy[i][j].color==candy[i+1][j].color&&candy[i][j].color==candy[i+2][j].color){
                return 1;
            }
            if(j<9&&candy[i][j].color==candy[i][j+1].color&&candy[i][j].color==candy[i][j+2].color){
                return 1;
            }
        }
    }
    return 0;
}

void MainWindow::clearcandy()
{
    srand((unsigned)time(NULL));
    int i,j,k;
    while(check()){

        for(i=1;i<11;i++){
            for(j=1;j<11;j++){
                if(i<9&&candy[i][j].color==candy[i+1][j].color&&candy[i][j].color==candy[i+2][j].color){
                    for(k=0;k<3;k++){
                        candy[i+k][j].deleted=true;
                    }
                }
                if(j<9&&candy[i][j].color==candy[i][j+1].color&&candy[i][j].color==candy[i][j+2].color){
                    for(k=0;k<3;k++){
                        candy[i][j+k].deleted=true;
                    }
                }

            }
        }
        for(i=1;i<11;i++){
            for(j=1;j<11;j++){
                if(start==true&&((candy[i][j].type==0&&candy[i+1][j].type==0&&candy[i+2][j].type==0&&candy[i-1][j].type==0&&candy[i-2][j].type==0&&i<9&&i>2&&candy[i][j].color==candy[i+1][j].color&&candy[i][j].color==candy[i+2][j].color&&candy[i][j].color==candy[i-1][j].color&&candy[i][j].color==candy[i-2][j].color)||(candy[i][j].type==0&&candy[i][j+1].type==0&&candy[i][j+2].type==0&&candy[i][j-1].type==0&&candy[i][j-2].type==0&&j<9&&j>2&&candy[i][j].color==candy[i][j+1].color&&candy[i][j].color==candy[i][j+2].color&&candy[i][j].color==candy[i][j-1].color&&candy[i][j].color==candy[i][j-2].color))){
                    candy[i][j].type=4;
                    candy[i][j].color=5;
                    candy[i][j].deleted=false;
                }
            }
        }
        for(i=1;i<11;i++){
            for(j=1;j<11;j++){
                if(start==true&&((candy[i][j].type==0&&candy[i+1][j].type==0&&candy[i+2][j].type==0&&candy[i][j+1].type==0&&candy[i][j+2].type==0&&candy[i][j].color==candy[i+1][j].color&&candy[i][j].color==candy[i+2][j].color&&candy[i][j].color==candy[i][j+1].color&&candy[i][j].color==candy[i][j+2].color&&i<9&&j<9)||(candy[i][j].type==0&&candy[i-1][j].type==0&&candy[i-2][j].type==0&&candy[i][j+1].type==0&&candy[i][j+2].type==0&&candy[i][j].color==candy[i-1][j].color&&candy[i][j].color==candy[i-2][j].color&&candy[i][j].color==candy[i][j+1].color&&candy[i][j].color==candy[i][j+2].color&&i>2&&j<9)||(candy[i][j].type==0&&candy[i-1][j].type==0&&candy[i-2][j].type==0&&candy[i][j-1].type==0&&candy[i][j-2].type==0&&candy[i][j].color==candy[i-1][j].color&&candy[i][j].color==candy[i-2][j].color&&candy[i][j].color==candy[i][j-1].color&&candy[i][j].color==candy[i][j-2].color&&i>2&&j>2)||(candy[i][j].type==0&&candy[i+1][j].type==0&&candy[i+2][j].type==0&&candy[i][j-1].type==0&&candy[i][j-2].type==0&&candy[i][j].color==candy[i+1][j].color&&candy[i][j].color==candy[i+2][j].color&&candy[i][j].color==candy[i][j-1].color&&candy[i][j].color==candy[i][j-2].color&&i<9&&j>2)||(candy[i][j].type==0&&candy[i+1][j].type==0&&candy[i-1][j].type==0&&candy[i][j+1].type==0&&candy[i][j+2].type==0&&candy[i][j].color==candy[i+1][j].color&&candy[i][j].color==candy[i-1][j].color&&candy[i][j].color==candy[i][j+1].color&&candy[i][j].color==candy[i][j+2].color&&i>1&&i<10&&j<9)||(candy[i][j].type==0&&candy[i-1][j].type==0&&candy[i-2][j].type==0&&candy[i][j+1].type==0&&candy[i][j-1].type==0&&candy[i][j].color==candy[i-1][j].color&&candy[i][j].color==candy[i-2][j].color&&candy[i][j].color==candy[i][j-1].color&&candy[i][j].color==candy[i][j+1].color&&i<9&&j<10&&j>1)||(candy[i][j].type==0&&candy[i+1][j].type==0&&candy[i-1][j].type==0&&candy[i][j-1].type==0&&candy[i][j-2].type==0&&candy[i][j].color==candy[i-1][j].color&&candy[i][j].color==candy[i+1][j].color&&candy[i][j].color==candy[i][j-1].color&&candy[i][j].color==candy[i][j-2].color&&i<10&&i>1&&j>2)||(candy[i][j].type==0&&candy[i+1][j].type==0&&candy[i+2][j].type==0&&candy[i][j+1].type==0&&candy[i][j-1].type==0&&candy[i][j].color==candy[i+1][j].color&&candy[i][j].color==candy[i+2][j].color&&candy[i][j].color==candy[i][j-1].color&&candy[i][j].color==candy[i][j+1].color&&i<9&&j>1&&j<10)||(candy[i][j].type==0&&candy[i+1][j].type==0&&candy[i-1][j].type==0&&candy[i][j+1].type==0&&candy[i][j-1].type==0&&candy[i][j].color==candy[i+1][j].color&&candy[i][j].color==candy[i-1][j].color&&candy[i][j].color==candy[i][j+1].color&&candy[i][j].color==candy[i][j-1].color&&i>1&&i<10&&j>1&&j<10))){
                    candy[i][j].type=3;
                    candy[i][j].deleted=false;
                }
            }
        }
        for(i=1;i<11;i++){
            for(j=1;j<11;j++){
                if(i<8&&start==true&&candy[i][j].type==0&&candy[i+1][j].type==0&&candy[i+2][j].type==0&&candy[i+3][j].type==0&&candy[i][j].color==candy[i+1][j].color&&candy[i][j].color==candy[i+2][j].color&&candy[i][j].color==candy[i+3][j].color){
                    candy[i+1][j].type=2;
                    candy[i+1][j].deleted=false;
                }
            }
        }
        for(i=1;i<11;i++){
            for(j=1;j<11;j++){
                if(j<8&&start==true&&candy[i][j].type==0&&candy[i][j+1].type==0&&candy[i][j+2].type==0&&candy[i][j+3].type==0&&candy[i][j].color==candy[i][j+1].color&&candy[i][j].color==candy[i][j+2].color&&candy[i][j].color==candy[i][j+3].color){
                    candy[i][j+1].type=1;
                    candy[i][j+1].deleted=false;
                }
            }
        }
        delay();
        deletecandy();
        showcandy();
    }
}

void MainWindow::delay()
{
    QTime dietime = QTime::currentTime().addMSecs(25);
    while(QTime::currentTime()<dietime){
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}

void MainWindow::deletecandy()
{
    srand((unsigned)time(NULL));
    int i,j,k,l,m;
    bool nodelete=false,special=false;
    while(!special){
    for(i=1;i<11;i++){
        for(j=1;j<11;j++){
            if(candy[i][j].deleted==true&&candy[i][j].type==4){
                m=rand()%4+1;
                for(k=1;k<11;k++){
                    for(l=1;l<11;l++){
                        if(candy[m][l].color==m){
                            candy[m][l].deleted=true;
                        }
                    }
                }
                candy[i][j].deleted=true;
                candy[i][j].type=0;
            }
            if(candy[i][j].deleted==true&&candy[i][j].type==3){
                for(k=i-1;k<i+2;k++){
                    for(l=j-1;l<j+2;l++){
                        candy[k][l].deleted=true;
                    }
                }
                candy[i][j].type=0;
            }
            if(candy[i][j].deleted==true&&candy[i][j].type==2){
                for(k=1;k<11;k++){
                    candy[i][k].deleted=true;
                }
                candy[i][j].type=0;
            }
            if(candy[i][j].deleted==true&&candy[i][j].type==1){
                for(k=1;k<11;k++){
                    candy[k][j].deleted=true;
                }
                candy[i][j].type=0;
            }
        }
    }
    special=true;
    for(i=1;i<11;i++){
        for(j=1;j<11;j++){
            if(candy[i][j].type!=0&&candy[i][j].deleted==true){
                special=false;
            }
        }
    }
    }
    for(i=1;i<11;i++){
        for(j=1;j<11;j++){
            if(candy[i][j].deleted==true&&start==true){
                candy[i][j].color=0;
                sco=sco+60;
                QString str=QString::number(sco);
                ui->score->setText(str);
                if(sco>35000){
                    ui->star1->setPixmap(QPixmap(":/new/prefix1/star_yes.png"));
                }
                if(sco>45000){
                    ui->star2->setPixmap(QPixmap(":/new/prefix1/star_yes.png"));
                }
                if(sco>50000){
                    ui->star3->setPixmap(QPixmap(":/new/prefix1/star_yes.png"));
                }
                showcandy();
                delay();
            }
        }
    }
    while(nodelete==false){
    for(i=1;i<11;i++){
        for(j=1;j<11;j++){
            if(candy[i][j].deleted==true&&j==1){
                candy[i][j].color=rand()%4+1;
                candy[i][j].type=0;
                candy[i][j].deleted=false;
                if(start){
                showcandy();
                delay();
                }
            }
            else if(j>1&&candy[i][j].deleted==true){
                    candy[i][j].color=candy[i][j-1].color;
                    candy[i][j-1].color=0;
                    candy[i][j].type=candy[i][j-1].type;
                    candy[i][j].deleted=false;
                    candy[i][j-1].deleted=true;
                    if(start){
                    showcandy();
                    delay();
                    }
            }
        }
    }
    nodelete=true;
    for(i=1;i<11;i++){
        for(j=1;j<11;j++){
            if(candy[i][j].deleted){
                nodelete=false;
            }
        }
    }
    }
}

void MainWindow::gameover()
{
    int i,j;
    if(sco>35000){
        for(i=step;i>0;i--){
            sco=sco+2500;
            step=step-1;
            QString st=QString::number(step);
            ui->step->setText(st);
            QString str=QString::number(sco);
            ui->score->setText(str);

            delay();
            delay();
            delay();
            delay();
            if(sco>35000){
                ui->star1->setPixmap(QPixmap(":/new/prefix1/star_yes.png"));
            }
            if(sco>45000){
                ui->star2->setPixmap(QPixmap(":/new/prefix1/star_yes.png"));
            }
            if(sco>50000){
                ui->star3->setPixmap(QPixmap(":/new/prefix1/star_yes.png"));
            }
        }
        ui->gameover->setPixmap(QPixmap(":/new/prefix1/wing.jpg"));
        ui->gameover->show();
    }
    else{
        ui->gameover->setPixmap(QPixmap(":/new/prefix1/gameoverg.jpg"));
        ui->gameover->show();
    }
    for(i=1;i<11;i++){
        for(j=1;j<11;j++){
            b[i][j]->close();
        }
    }
    start=false;
    canmove=false;
    ui->restart->show();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    srand((unsigned)time(NULL));
    canmove=true;
    start=false;
    sco=0;
    step=15;
    int i,j;
    ui->setupUi(this);
    ui->background->setPixmap(QPixmap(":/new/prefix1/frameg.jpg"));
    ui->star1->setPixmap(QPixmap(":/new/prefix1/star_no.png"));
    ui->star2->setPixmap(QPixmap(":/new/prefix1/star_no.png"));
    ui->star3->setPixmap(QPixmap(":/new/prefix1/star_no.png"));
    for(i=1;i<11;i++){
        for(j=1;j<11;j++){
            b[i][j]=new QLabel("i",this);
            b[i][j]->setGeometry(QRect(QPoint((i-1)*50,100+(j-1)*50),QSize(50,50)));
            b[i][j]->setFrameStyle(QFrame::Box);
        }
    }
    for(i=1;i<11;i++){
        for(j=1;j<11;j++){
            candy[i][j].color=rand()%4+1;
        }
    }
    while(check()){
        clearcandy();
    }
    QString st=QString::number(step);
    ui->step->setText(st);
    ui->restart->close();
    showcandy();
    start=true;
    choose=false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_restart_clicked()
{
    int i,j;
    step=15;
    sco=0;
    for(i=1;i<11;i++){
        for(j=1;j<11;j++){
            candy[i][j].color=rand()%4+1;
            candy[i][j].type=0;
        }
    }
    while(check()){
        clearcandy();
    }
    start=true;
    canmove=true;
    showcandy();
    ui->gameover->close();
    ui->restart->close();
    for(i=1;i<11;i++){
        for(j=1;j<11;j++){
            b[i][j]->show();
        }
    }
    ui->star1->setPixmap(QPixmap(":/new/prefix1/star_no.png"));
    ui->star2->setPixmap(QPixmap(":/new/prefix1/star_no.png"));
    ui->star3->setPixmap(QPixmap(":/new/prefix1/star_no.png"));
    QString st=QString::number(step);
    ui->step->setText(st);
    QString str=QString::number(sco);
    ui->score->setText(str);
}
