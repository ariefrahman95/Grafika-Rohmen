#include "Notification.hpp"
#include <math.h>

Notification::Notification() {
    pol = new Polygon2[19] {{4},{4},{4},{4},{4},{4},{4},{4},{4},{4},{4},{4},{4},{4},{4},{4},{4},{4},{4}};
    drawApa = 0;
}

Notification::~Notification() {
    delete pol;
}

void Notification::drawYou(){
	//#pol1(4);
	pol[0].define(0,140,20);
	pol[0].define(1,160,20);
	pol[0].define(2,140,100);
	pol[0].define(3,160,100);
	pol[0].hubung(0,1);
	pol[0].hubung(1,3);
	pol[0].hubung(0,2);
	pol[0].hubung(2,3);

	//pol2(4);
	pol[1].define(0,160,100);
	pol[1].define(1,180,100);
	pol[1].define(2,160,140);
	pol[1].define(3,180,140);
	pol[1].hubung(0,1);
	pol[1].hubung(1,3);
	pol[1].hubung(0,2);
	pol[1].hubung(2,3);

	//pol3(4);
	pol[2].define(0,180,140);
	pol[2].define(1,200,140);
	pol[2].define(2,180,220);
	pol[2].define(3,200,220);
	pol[2].hubung(0,1);
	pol[2].hubung(1,3);
	pol[2].hubung(0,2);
	pol[2].hubung(2,3);

	//pol4(4);
	pol[3].define(0,200,100);
	pol[3].define(1,220,100);
	pol[3].define(2,200,140);
	pol[3].define(3,220,140);
	pol[3].hubung(0,1);
	pol[3].hubung(1,3);
	pol[3].hubung(0,2);
	pol[3].hubung(2,3);

	//pol5(4);
	pol[4].define(0,220,20);
	pol[4].define(1,240,20);
	pol[4].define(2,220,100);
	pol[4].define(3,240,100);
	pol[4].hubung(0,1);
	pol[4].hubung(1,3);
	pol[4].hubung(0,2);
	pol[4].hubung(2,3);

	//pol6(4);
	pol[5].define(0,270,60);
	pol[5].define(1,290,60);
	pol[5].define(2,270,180);
	pol[5].define(3,290,180);
	pol[5].hubung(0,1);
	pol[5].hubung(1,3);
	pol[5].hubung(0,2);
	pol[5].hubung(2,3);

	//pol7(4);
	pol[6].define(0,290,180);
	pol[6].define(1,310,180);
	pol[6].define(2,290,200);
	pol[6].define(3,310,200);
	pol[6].hubung(0,1);
	pol[6].hubung(1,3);
	pol[6].hubung(0,2);
	pol[6].hubung(2,3);

	//pol8(4);
	pol[7].define(0,310,200);
	pol[7].define(1,330,200);
	pol[7].define(2,310,220);
	pol[7].define(3,330,220);
	pol[7].hubung(0,1);
	pol[7].hubung(1,3);
	pol[7].hubung(0,2);
	pol[7].hubung(2,3);

	//pol9(4);
	pol[8].define(0,330,180);
	pol[8].define(1,350,180);
	pol[8].define(2,330,200);
	pol[8].define(3,350,200);
	pol[8].hubung(0,1);
	pol[8].hubung(1,3);
	pol[8].hubung(0,2);
	pol[8].hubung(2,3);

	//pol0(4);
	pol[9].define(0,350,60);
	pol[9].define(1,370,60);
	pol[9].define(2,350,180);
	pol[9].define(3,370,180);
	pol[9].hubung(0,1);
	pol[9].hubung(1,3);
	pol[9].hubung(0,2);
	pol[9].hubung(2,3);

	//pol11(4);
	pol[10].define(0,330,40);
	pol[10].define(1,350,40);
	pol[10].define(2,330,60);
	pol[10].define(3,350,60);
	pol[10].hubung(0,1);
	pol[10].hubung(1,3);
	pol[10].hubung(0,2);
	pol[10].hubung(2,3);

	//pol12(4);
	pol[11].define(0,310,20);
	pol[11].define(1,330,20);
	pol[11].define(2,310,40);
	pol[11].define(3,330,40);
	pol[11].hubung(0,1);
	pol[11].hubung(1,3);
	pol[11].hubung(0,2);
	pol[11].hubung(2,3);

	//pol13(4);
	pol[12].define(0,290,40);
	pol[12].define(1,310,40);
	pol[12].define(2,290,60);
	pol[12].define(3,310,60);
	pol[12].hubung(0,1);
	pol[12].hubung(1,3);
	pol[12].hubung(0,2);
	pol[12].hubung(2,3);

	//pol14(4);
	pol[13].define(0,400,20);
	pol[13].define(1,420,20);
	pol[13].define(2,400,170);
	pol[13].define(3,420,170);
	pol[13].hubung(0,1);
	pol[13].hubung(1,3);
	pol[13].hubung(0,2);
	pol[13].hubung(2,3);

	//pol15(4);
	pol[14].define(0,420,170);
	pol[14].define(1,440,170);
	pol[14].define(2,420,195);
	pol[14].define(3,440,195);
	pol[14].hubung(0,1);
	pol[14].hubung(1,3);
	pol[14].hubung(0,2);
	pol[14].hubung(2,3);

	//pol16(4);
	pol[15].define(0,440,195);
	pol[15].define(1,460,195);
	pol[15].define(2,440,220);
	pol[15].define(3,460,220);
	pol[15].hubung(0,1);
	pol[15].hubung(1,3);
	pol[15].hubung(0,2);
	pol[15].hubung(2,3);

	//pol17(4);
	pol[16].define(0,460,170);
	pol[16].define(1,480,170);
	pol[16].define(2,460,195);
	pol[16].define(3,480,195);
	pol[16].hubung(0,1);
	pol[16].hubung(1,3);
	pol[16].hubung(0,2);
	pol[16].hubung(2,3);

	//pol18(4);
	pol[17].define(0,480,20);
	pol[17].define(1,500,20);
	pol[17].define(2,480,170);
	pol[17].define(3,500,170);
	pol[17].hubung(0,1);
	pol[17].hubung(1,3);
	pol[17].hubung(0,2);
	pol[17].hubung(2,3);
    
    drawApa = 1;
}

void Notification::drawWin(){
	//pol1(4);
	pol[0].define(0,140,260);
	pol[0].define(1,160,260);
	pol[0].define(2,140,460);
	pol[0].define(3,160,460);
	pol[0].hubung(0,1);
	pol[0].hubung(1,3);
	pol[0].hubung(0,2);
	pol[0].hubung(2,3);

	//pol2(4);
	pol[1].define(0,160,420);
	pol[1].define(1,180,420);
	pol[1].define(2,160,440);
	pol[1].define(3,180,440);
	pol[1].hubung(0,1);
	pol[1].hubung(1,3);
	pol[1].hubung(0,2);
	pol[1].hubung(2,3);

	//pol3(4);
	pol[2].define(0,180,400);
	pol[2].define(1,200,400);
	pol[2].define(2,180,420);
	pol[2].define(3,200,420);
	pol[2].hubung(0,1);
	pol[2].hubung(1,3);
	pol[2].hubung(0,2);
	pol[2].hubung(2,3);

	//pol4(4);
	pol[3].define(0,200,420);
	pol[3].define(1,220,420);
	pol[3].define(2,200,440);
	pol[3].define(3,220,440);
	pol[3].hubung(0,1);
	pol[3].hubung(1,3);
	pol[3].hubung(0,2);
	pol[3].hubung(2,3);

	//pol5(4);
	pol[4].define(0,220,260);
	pol[4].define(1,240,260);
	pol[4].define(2,220,460);
	pol[4].define(3,240,460);
	pol[4].hubung(0,1);
	pol[4].hubung(1,3);
	pol[4].hubung(0,2);
	pol[4].hubung(2,3);

	//pol6(4);
	pol[5].define(0,300,260);
	pol[5].define(1,340,260);
	pol[5].define(2,300,460);
	pol[5].define(3,340,460);
	pol[5].hubung(0,1);
	pol[5].hubung(1,3);
	pol[5].hubung(0,2);
	pol[5].hubung(2,3);

	//pol7(4);
	pol[6].define(0,400,260);
	pol[6].define(1,420,260);
	pol[6].define(2,400,460);
	pol[6].define(3,420,460);
	pol[6].hubung(0,1);
	pol[6].hubung(1,3);
	pol[6].hubung(0,2);
	pol[6].hubung(2,3);

	//pol8(4);
	pol[7].define(0,420,280);
	pol[7].define(1,440,280);
	pol[7].define(2,420,300);
	pol[7].define(3,440,300);
	pol[7].hubung(0,1);
	pol[7].hubung(1,3);
	pol[7].hubung(0,2);
	pol[7].hubung(2,3);

	//pol9(4);
	pol[8].define(0,440,300);
	pol[8].define(1,460,300);
	pol[8].define(2,440,320);
	pol[8].define(3,460,320);
	pol[8].hubung(0,1);
	pol[8].hubung(1,3);
	pol[8].hubung(0,2);
	pol[8].hubung(2,3);

	//pol0(4);
	pol[9].define(0,460,320);
	pol[9].define(1,480,320);
	pol[9].define(2,460,340);
	pol[9].define(3,480,340);
	pol[9].hubung(0,1);
	pol[9].hubung(1,3);
	pol[9].hubung(0,2);
	pol[9].hubung(2,3);

	//pol11(4);
	pol[10].define(0,480,260);
	pol[10].define(1,500,260);
	pol[10].define(2,480,460);
	pol[10].define(3,500,460);
	pol[10].hubung(0,1);
	pol[10].hubung(1,3);
	pol[10].hubung(0,2);
	pol[10].hubung(2,3);
    
    drawApa = 2;
}

void Notification::drawLose(){
	//pol1(4);
	pol[0].define(0,130,260);
	pol[0].define(1,150,260);
	pol[0].define(2,130,460);
	pol[0].define(3,150,460);
	pol[0].hubung(0,1);
	pol[0].hubung(1,3);
	pol[0].hubung(0,2);
	pol[0].hubung(2,3);

	//pol2(4);
	pol[1].define(0,150,440);
	pol[1].define(1,210,440);
	pol[1].define(2,150,460);
	pol[1].define(3,210,460);
	pol[1].hubung(0,1);
	pol[1].hubung(1,3);
	pol[1].hubung(0,2);
	pol[1].hubung(2,3);

	//pol3(4);
	pol[2].define(0,230,280);
	pol[2].define(1,250,280);
	pol[2].define(2,230,440);
	pol[2].define(3,250,440);
	pol[2].hubung(0,1);
	pol[2].hubung(1,3);
	pol[2].hubung(0,2);
	pol[2].hubung(2,3);

	//pol4(4);
	pol[3].define(0,250,440);
	pol[3].define(1,290,440);
	pol[3].define(2,250,460);
	pol[3].define(3,290,460);
	pol[3].hubung(0,1);
	pol[3].hubung(1,3);
	pol[3].hubung(0,2);
	pol[3].hubung(2,3);

	//pol5(4);
	pol[4].define(0,290,280);
	pol[4].define(1,310,280);
	pol[4].define(2,290,440);
	pol[4].define(3,310,440);
	pol[4].hubung(0,1);
	pol[4].hubung(1,3);
	pol[4].hubung(0,2);
	pol[4].hubung(2,3);

	//pol6(4);
	pol[5].define(0,250,260);
	pol[5].define(1,290,260);
	pol[5].define(2,250,280);
	pol[5].define(3,290,280);
	pol[5].hubung(0,1);
	pol[5].hubung(1,3);
	pol[5].hubung(0,2);
	pol[5].hubung(2,3);

	//pol7(4);
	pol[6].define(0,330,260);
	pol[6].define(1,390,260);
	pol[6].define(2,330,280);
	pol[6].define(3,390,280);
	pol[6].hubung(0,1);
	pol[6].hubung(1,3);
	pol[6].hubung(0,2);
	pol[6].hubung(2,3);

	//pol8(4);
	pol[7].define(0,330,280);
	pol[7].define(1,360,280);
	pol[7].define(2,330,300);
	pol[7].define(3,360,300);
	pol[7].hubung(0,1);
	pol[7].hubung(1,3);
	pol[7].hubung(0,2);
	pol[7].hubung(2,3);

	//pol9(4);
	pol[8].define(0,330,300);
	pol[8].define(1,410,300);
	pol[8].define(2,330,320);
	pol[8].define(3,410,320);
	pol[8].hubung(0,1);
	pol[8].hubung(1,3);
	pol[8].hubung(0,2);
	pol[8].hubung(2,3);

	//pol0(4);
	pol[9].define(0,390,320);
	pol[9].define(1,410,320);
	pol[9].define(2,390,440);
	pol[9].define(3,410,440);
	pol[9].hubung(0,1);
	pol[9].hubung(1,3);
	pol[9].hubung(0,2);
	pol[9].hubung(2,3);

	//pol11(4);
	pol[10].define(0,330,440);
	pol[10].define(1,410,440);
	pol[10].define(2,330,460);
	pol[10].define(3,410,460);
	pol[10].hubung(0,1);
	pol[10].hubung(1,3);
	pol[10].hubung(0,2);
	pol[10].hubung(2,3);

	//pol12(4);
	pol[11].define(0,410,260);
	pol[11].define(1,430,260);
	pol[11].define(2,410,460);
	pol[11].define(3,430,460);
	pol[11].hubung(0,1);
	pol[11].hubung(1,3);
	pol[11].hubung(0,2);
	pol[11].hubung(2,3);

	//pol13(4);
	pol[12].define(0,430,260);
	pol[12].define(1,490,260);
	pol[12].define(2,430,280);
	pol[12].define(3,490,280);
	pol[12].hubung(0,1);
	pol[12].hubung(1,3);
	pol[12].hubung(0,2);
	pol[12].hubung(2,3);

	//pol14(4);
	pol[13].define(0,430,310);
	pol[13].define(1,470,310);
	pol[13].define(2,430,330);
	pol[13].define(3,470,330);
	pol[13].hubung(0,1);
	pol[13].hubung(1,3);
	pol[13].hubung(0,2);
	pol[13].hubung(2,3);

	//pol15(4);
	pol[14].define(0,430,440);
	pol[14].define(1,490,440);
	pol[14].define(2,430,460);
	pol[14].define(3,490,460);
	pol[14].hubung(0,1);
	pol[14].hubung(1,3);
	pol[14].hubung(0,2);
	pol[14].hubung(2,3);
    
    drawApa = 3;
}

void Notification::Draw(Canvas& canvas) {
    int i;
    
    switch(drawApa) {
        case 1:
            for(i = 0; i < 18; i++) {
                pol[i].setColor(255);
                pol[i].Draw(canvas);
            }
            break;
        case 2:
            for(i = 0; i < 11; i++) {
                pol[i].setColor(255);
                pol[i].Draw(canvas);
            }
            break;
        case 3:
            for(i = 0; i < 15; i++) {
                pol[i].setColor(255);
                pol[i].Draw(canvas);
            }
            break;
        default:
            break;
    }
}