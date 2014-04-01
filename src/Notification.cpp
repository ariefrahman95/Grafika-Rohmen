#include "Notification.hpp"
#include <math.h>

void Notification::drawYou(){
	pol1(4);
	pol1.define(0,140,20);
	pol1.define(1,160,20);
	pol1.define(2,140,100);
	pol1.define(3,160,100);
	pol1.hubung(0,1);
	pol1.hubung(1,3);
	pol1.hubung(0,2);
	pol1.hubung(2,3);

	pol2(4);
	pol2.define(0,160,100);
	pol2.define(1,180,100);
	pol2.define(2,160,140);
	pol2.define(3,180,140);
	pol2.hubung(0,1);
	pol2.hubung(1,3);
	pol2.hubung(0,2);
	pol2.hubung(2,3);

	pol3(4);
	pol3.define(0,180,140);
	pol3.define(1,200,140);
	pol3.define(2,180,220);
	pol3.define(3,200,220);
	pol3.hubung(0,1);
	pol3.hubung(1,3);
	pol3.hubung(0,2);
	pol3.hubung(2,3);

	pol4(4);
	pol4.define(0,200,100);
	pol4.define(1,220,100);
	pol4.define(2,200,140);
	pol4.define(3,220,140);
	pol4.hubung(0,1);
	pol4.hubung(1,3);
	pol4.hubung(0,2);
	pol4.hubung(2,3);

	pol5(4);
	pol5.define(0,220,20);
	pol5.define(1,240,20);
	pol5.define(2,220,100);
	pol5.define(3,240,100);
	pol5.hubung(0,1);
	pol5.hubung(1,3);
	pol5.hubung(0,2);
	pol5.hubung(2,3);

	pol6(4);
	pol6.define(0,270,60);
	pol6.define(1,290,60);
	pol6.define(2,270,180);
	pol6.define(3,290,180);
	pol6.hubung(0,1);
	pol6.hubung(1,3);
	pol6.hubung(0,2);
	pol6.hubung(2,3);

	pol7(4);
	pol7.define(0,290,180);
	pol7.define(1,310,180);
	pol7.define(2,290,200);
	pol7.define(3,310,200);
	pol7.hubung(0,1);
	pol7.hubung(1,3);
	pol7.hubung(0,2);
	pol7.hubung(2,3);

	pol8(4);
	pol8.define(0,310,200);
	pol8.define(1,330,200);
	pol8.define(2,310,220);
	pol8.define(3,330,220);
	pol8.hubung(0,1);
	pol8.hubung(1,3);
	pol8.hubung(0,2);
	pol8.hubung(2,3);

	pol9(4);
	pol9.define(0,330,180);
	pol9.define(1,350,180);
	pol9.define(2,330,200);
	pol9.define(3,350,200);
	pol9.hubung(0,1);
	pol9.hubung(1,3);
	pol9.hubung(0,2);
	pol9.hubung(2,3);

	pol10(4);
	pol10.define(0,350,60);
	pol10.define(1,370,60);
	pol10.define(2,350,180);
	pol10.define(3,370,180);
	pol10.hubung(0,1);
	pol10.hubung(1,3);
	pol10.hubung(0,2);
	pol10.hubung(2,3);

	pol11(4);
	pol11.define(0,330,40);
	pol11.define(1,350,40);
	pol11.define(2,330,60);
	pol11.define(3,350,60);
	pol11.hubung(0,1);
	pol11.hubung(1,3);
	pol11.hubung(0,2);
	pol11.hubung(2,3);

	pol12(4);
	pol12.define(0,310,20);
	pol12.define(1,330,20);
	pol12.define(2,310,40);
	pol12.define(3,330,40);
	pol12.hubung(0,1);
	pol12.hubung(1,3);
	pol12.hubung(0,2);
	pol12.hubung(2,3);

	pol13(4);
	pol13.define(0,290,40);
	pol13.define(1,310,40);
	pol13.define(2,290,60);
	pol13.define(3,310,60);
	pol13.hubung(0,1);
	pol13.hubung(1,3);
	pol13.hubung(0,2);
	pol13.hubung(2,3);

	pol14(4);
	pol14.define(0,400,20);
	pol14.define(1,420,20);
	pol14.define(2,400,170);
	pol14.define(3,420,170);
	pol14.hubung(0,1);
	pol14.hubung(1,3);
	pol14.hubung(0,2);
	pol14.hubung(2,3);

	pol15(4);
	pol15.define(0,420,170);
	pol15.define(1,440,170);
	pol15.define(2,420,195);
	pol15.define(3,440,195);
	pol15.hubung(0,1);
	pol15.hubung(1,3);
	pol15.hubung(0,2);
	pol15.hubung(2,3);

	pol16(4);
	pol16.define(0,440,195);
	pol16.define(1,460,195);
	pol16.define(2,440,220);
	pol16.define(3,460,220);
	pol16.hubung(0,1);
	pol16.hubung(1,3);
	pol16.hubung(0,2);
	pol16.hubung(2,3);

	pol17(4);
	pol17.define(0,460,170);
	pol17.define(1,480,170);
	pol17.define(2,460,195);
	pol17.define(3,480,195);
	pol17.hubung(0,1);
	pol17.hubung(1,3);
	pol17.hubung(0,2);
	pol17.hubung(2,3);

	pol18(4);
	pol18.define(0,480,20);
	pol18.define(1,500,20);
	pol18.define(2,480,170);
	pol18.define(3,500,170);
	pol18.hubung(0,1);
	pol18.hubung(1,3);
	pol18.hubung(0,2);
	pol18.hubung(2,3);
}

void Notification::drawWin(){
	pol1(4);
	pol1.define(0,140,260);
	pol1.define(1,160,260);
	pol1.define(2,140,460);
	pol1.define(3,160,460);
	pol1.hubung(0,1);
	pol1.hubung(1,3);
	pol1.hubung(0,2);
	pol1.hubung(2,3);

	pol2(4);
	pol2.define(0,160,420);
	pol2.define(1,180,420);
	pol2.define(2,160,440);
	pol2.define(3,180,440);
	pol2.hubung(0,1);
	pol2.hubung(1,3);
	pol2.hubung(0,2);
	pol2.hubung(2,3);

	pol3(4);
	pol3.define(0,180,400);
	pol3.define(1,200,400);
	pol3.define(2,180,420);
	pol3.define(3,200,420);
	pol3.hubung(0,1);
	pol3.hubung(1,3);
	pol3.hubung(0,2);
	pol3.hubung(2,3);

	pol4(4);
	pol4.define(0,200,420);
	pol4.define(1,220,420);
	pol4.define(2,200,440);
	pol4.define(3,220,440);
	pol4.hubung(0,1);
	pol4.hubung(1,3);
	pol4.hubung(0,2);
	pol4.hubung(2,3);

	pol5(4);
	pol5.define(0,220,260);
	pol5.define(1,240,260);
	pol5.define(2,220,460);
	pol5.define(3,240,460);
	pol5.hubung(0,1);
	pol5.hubung(1,3);
	pol5.hubung(0,2);
	pol5.hubung(2,3);

	pol6(4);
	pol6.define(0,300,260);
	pol6.define(1,340,260);
	pol6.define(2,300,460);
	pol6.define(3,340,460);
	pol6.hubung(0,1);
	pol6.hubung(1,3);
	pol6.hubung(0,2);
	pol6.hubung(2,3);

	pol7(4);
	pol7.define(0,400,260);
	pol7.define(1,420,260);
	pol7.define(2,400,460);
	pol7.define(3,420,460);
	pol7.hubung(0,1);
	pol7.hubung(1,3);
	pol7.hubung(0,2);
	pol7.hubung(2,3);

	pol8(4);
	pol8.define(0,420,280);
	pol8.define(1,440,280);
	pol8.define(2,420,300);
	pol8.define(3,440,300);
	pol8.hubung(0,1);
	pol8.hubung(1,3);
	pol8.hubung(0,2);
	pol8.hubung(2,3);

	pol9(4);
	pol9.define(0,440,300);
	pol9.define(1,460,300);
	pol9.define(2,440,320);
	pol9.define(3,460,320);
	pol9.hubung(0,1);
	pol9.hubung(1,3);
	pol9.hubung(0,2);
	pol9.hubung(2,3);

	pol10(4);
	pol10.define(0,460,320);
	pol10.define(1,480,320);
	pol10.define(2,460,340);
	pol10.define(3,480,340);
	pol10.hubung(0,1);
	pol10.hubung(1,3);
	pol10.hubung(0,2);
	pol10.hubung(2,3);

	pol11(4);
	pol11.define(0,480,260);
	pol11.define(1,500,260);
	pol11.define(2,480,460);
	pol11.define(3,500,460);
	pol11.hubung(0,1);
	pol11.hubung(1,3);
	pol11.hubung(0,2);
	pol11.hubung(2,3);
}

void Notification::drawLose(){
	pol1(4);
	pol1.define(0,130,260);
	pol1.define(1,150,260);
	pol1.define(2,130,460);
	pol1.define(3,150,460);
	pol1.hubung(0,1);
	pol1.hubung(1,3);
	pol1.hubung(0,2);
	pol1.hubung(2,3);

	pol2(4);
	pol2.define(0,150,440);
	pol2.define(1,210,440);
	pol2.define(2,150,460);
	pol2.define(3,210,460);
	pol2.hubung(0,1);
	pol2.hubung(1,3);
	pol2.hubung(0,2);
	pol2.hubung(2,3);

	pol3(4);
	pol3.define(0,230,280);
	pol3.define(1,250,280);
	pol3.define(2,230,440);
	pol3.define(3,250,440);
	pol3.hubung(0,1);
	pol3.hubung(1,3);
	pol3.hubung(0,2);
	pol3.hubung(2,3);

	pol4(4);
	pol4.define(0,250,440);
	pol4.define(1,290,440);
	pol4.define(2,250,460);
	pol4.define(3,290,460);
	pol4.hubung(0,1);
	pol4.hubung(1,3);
	pol4.hubung(0,2);
	pol4.hubung(2,3);

	pol5(4);
	pol5.define(0,290,280);
	pol5.define(1,310,280);
	pol5.define(2,290,440);
	pol5.define(3,310,440);
	pol5.hubung(0,1);
	pol5.hubung(1,3);
	pol5.hubung(0,2);
	pol5.hubung(2,3);

	pol6(4);
	pol6.define(0,250,260);
	pol6.define(1,290,260);
	pol6.define(2,250,280);
	pol6.define(3,290,280);
	pol6.hubung(0,1);
	pol6.hubung(1,3);
	pol6.hubung(0,2);
	pol6.hubung(2,3);

	pol7(4);
	pol7.define(0,330,260);
	pol7.define(1,390,260);
	pol7.define(2,330,280);
	pol7.define(3,390,280);
	pol7.hubung(0,1);
	pol7.hubung(1,3);
	pol7.hubung(0,2);
	pol7.hubung(2,3);

	pol8(4);
	pol8.define(0,330,280);
	pol8.define(1,360,280);
	pol8.define(2,330,300);
	pol8.define(3,360,300);
	pol8.hubung(0,1);
	pol8.hubung(1,3);
	pol8.hubung(0,2);
	pol8.hubung(2,3);

	pol9(4);
	pol9.define(0,330,300);
	pol9.define(1,410,300);
	pol9.define(2,330,320);
	pol9.define(3,410,320);
	pol9.hubung(0,1);
	pol9.hubung(1,3);
	pol9.hubung(0,2);
	pol9.hubung(2,3);

	pol10(4);
	pol10.define(0,390,320);
	pol10.define(1,410,320);
	pol10.define(2,390,440);
	pol10.define(3,410,440);
	pol10.hubung(0,1);
	pol10.hubung(1,3);
	pol10.hubung(0,2);
	pol10.hubung(2,3);

	pol11(4);
	pol11.define(0,330,440);
	pol11.define(1,410,440);
	pol11.define(2,330,460);
	pol11.define(3,410,460);
	pol11.hubung(0,1);
	pol11.hubung(1,3);
	pol11.hubung(0,2);
	pol11.hubung(2,3);

	pol12(4);
	pol12.define(0,410,260);
	pol12.define(1,430,260);
	pol12.define(2,410,460);
	pol12.define(3,430,460);
	pol12.hubung(0,1);
	pol12.hubung(1,3);
	pol12.hubung(0,2);
	pol12.hubung(2,3);

	pol13(4);
	pol13.define(0,430,260);
	pol13.define(1,490,260);
	pol13.define(2,430,280);
	pol13.define(3,490,280);
	pol13.hubung(0,1);
	pol13.hubung(1,3);
	pol13.hubung(0,2);
	pol13.hubung(2,3);

	pol14(4);
	pol14.define(0,430,310);
	pol14.define(1,470,310);
	pol14.define(2,430,330);
	pol14.define(3,470,330);
	pol14.hubung(0,1);
	pol14.hubung(1,3);
	pol14.hubung(0,2);
	pol14.hubung(2,3);

	pol15(4);
	pol15.define(0,430,440);
	pol15.define(1,490,440);
	pol15.define(2,430,460);
	pol15.define(3,490,460);
	pol15.hubung(0,1);
	pol15.hubung(1,3);
	pol15.hubung(0,2);
	pol15.hubung(2,3);
}