#include "Pemandangan.hpp"

Pemandangan::Pemandangan() {
    pemandangan = new Polygon2(7);
    jalan = new Polygon2(4);
    
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
}

Pemandangan::~Pemandangan() {
    delete pemandangan;
    delete jalan;
}

void Pemandangan::Draw(Canvas& canvas) {
    pemandangan->Draw(canvas);
    jalan->Draw(canvas);
    canvas.Fill(Point( 80,  1), 0, BLUE);
    canvas.Fill(Point(320,  1), 0, BLUE);
    canvas.Fill(Point(490,  1), 0, BLUE);
    canvas.Fill(Point(160, 10), 0, GREEN);
    canvas.Fill(Point(480, 10), 0, GREEN);
    
    canvas.Fill(Point(320, 230), 0, LIGHTGRAY);
}
