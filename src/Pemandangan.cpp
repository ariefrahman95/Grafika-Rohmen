#include "Pemandangan.hpp"

Pemandangan::Pemandangan() {
    pemandangan = new Polygon2(7);
    jalan = new Polygon2(4);
    marka_jalan = new Polygon2(4);
    
    pemandangan->setColor(255);
    pemandangan->define(0,   0,   0);
    pemandangan->define(1, 160,   0);
    pemandangan->define(2,   0, 220);
    pemandangan->define(3, 320, 220);
    pemandangan->define(4, 480,   0);
    pemandangan->define(5, 639, 220);
    pemandangan->define(6, 639,   0);
    pemandangan->hubung(0, 1);
    pemandangan->hubung(0, 2);
    pemandangan->hubung(1, 2);
    pemandangan->hubung(1, 3);
    pemandangan->hubung(1, 4);
    pemandangan->hubung(2, 3);
    pemandangan->hubung(3, 4);
    pemandangan->hubung(3, 5);
    pemandangan->hubung(4, 5);
    pemandangan->hubung(4, 6);
    pemandangan->hubung(5, 6);
    
    jalan->setColor(255);
    jalan->define(0, 240, 220);
    jalan->define(1, 400, 220);
    jalan->define(2, 60, 479);
    jalan->define(3, 579, 479);
    jalan->hubung(0, 1);
    jalan->hubung(0, 2);
    jalan->hubung(1, 3);
    jalan->hubung(2, 3);
    
    marka_jalan->setColor(255);
    marka_y = 220;
    iteration = 0;
    marka_jalan->define(0, 310, 220);
    marka_jalan->define(1, 330, 220);
    marka_jalan->define(2, 300, 300);
    marka_jalan->define(3, 340, 300);
    marka_jalan->hubung(0, 1);
    marka_jalan->hubung(0, 2);
    marka_jalan->hubung(1, 3);
    marka_jalan->hubung(2, 3);
}

Pemandangan::~Pemandangan() {
    delete pemandangan;
    delete jalan;
}

void Pemandangan::Draw(Canvas& canvas) {
    pemandangan->Draw(canvas);
    jalan->Draw(canvas);
    marka_jalan->Draw(canvas);
    canvas.FillFlood(Point( 80,  1), getpixel( 80,  1), LIGHTBLUE);
    canvas.FillFlood(Point(320,  1), getpixel(320,  1), LIGHTBLUE);
    canvas.FillFlood(Point(490,  1), getpixel(490,  1), LIGHTBLUE);
    canvas.FillFlood(Point(160, 10), getpixel(160, 10), BLUE);
    canvas.FillFlood(Point(480, 10), getpixel(480, 10), BLUE);
    
    canvas.FillFlood(Point(280, 230), getpixel(280, 230), DARKGRAY);
    canvas.FillFlood(Point(320, marka_y + 10), getpixel(320, marka_y + 10), WHITE);
}

void Pemandangan::Update() {
    if(marka_y >= 400) {
        marka_jalan->define(0, 310, 220);
        marka_jalan->define(1, 330, 220);
        marka_jalan->define(2, 300, 300);
        marka_jalan->define(3, 340, 300);
        marka_y = 220;
    }
    marka_jalan->scale(1.025);
    marka_jalan->translate(2, 3);
    marka_jalan->translate(3, 1);
    marka_y+=3;
}
