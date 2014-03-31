/**
 * Nama/NIM  : Setyo Legowo/13511071
 * Tanggal   : 30 Maret 2014
 * File      : Polygon.cpp
 * Deskripsi : Pendefinisian penggunaan Polygon.hpp
 */

#include "Polygon.hpp"
#include "Line.hpp"

Polygon2::Polygon2(int jumlah_titik) {
    this->n_titik = jumlah_titik;
    this->warna = 0;
    if(jumlah_titik < 3)
        return;
    
    int iterator;
    this->n_titik = jumlah_titik;
    for(iterator = 0; iterator < jumlah_titik; iterator++) {
        //Point p();
        this->listTitik.push_back(Point());
    }
}
Polygon2::~Polygon2() {
    this->n_titik = 0;
    this->warna = 0;
    this->listTitik.clear();
    this->listPasangan.clear();
}
Polygon2::Polygon2(const Polygon2& Pol) {
    int it;
    this->n_titik = Pol.n_titik;
    this->warna = Pol.warna;
    
    this->listTitik.clear();
    for(it = 0; it < this->n_titik; it++) {
        //Point p;
        this->listTitik.push_back(Point(Pol.listTitik.at(it)));
    }
    
    this->listPasangan.clear();
    int pasanganSize = Pol.listPasangan.size();
    for(it = 0; it < pasanganSize; it++) {
        int_tuple itpl = Pol.listPasangan.at(it);
        this->listPasangan.push_back(itpl);
    }
}
Polygon2& Polygon2::operator=(const Polygon2& Pol) {
    int it;
    this->n_titik = Pol.n_titik;
    this->warna = Pol.warna;
    
    this->listTitik.clear();
    for(it = 0; it < this->n_titik; it++) {
        Point p(Pol.listTitik.at(it));
        this->listTitik.push_back(p);
    }
    
    this->listPasangan.clear();
    int pasanganSize = Pol.listPasangan.size();
    for(it = 0; it < pasanganSize; it++) {
        int_tuple itpl = Pol.listPasangan.at(it);
        this->listPasangan.push_back(itpl);
    }
    
    return *this;
}

// ===
// METHODS
// ===
void Polygon2::setColor(int color) {
    this->warna = color;
}
void Polygon2::define(int index, double x, double y) {
    if(index >= this->n_titik || index < 0 || x < 0.0 || y < 0.0)
        return;
    
    Point p = this->listTitik.at(index);
    p.x = x;
    p.y = y;
    this->listTitik.at(index) = p;
}
void Polygon2::define(int index, const Point& point) {
    define(index, point.x, point.y);
}
void Polygon2::hubung(int index1, int index2) {
    if(index1 >= this->n_titik || index1 < 0
        || index2 >= this->n_titik || index2 < 0)
        return;
    
    // Mencari apakah titik pernah didefinisikan
    int it;
    int size = this->listPasangan.size();
    int_tuple itpl;
    for(it = 0; it < size; it++) {
        itpl = this->listPasangan.at(it);
        if((itpl.a == index1 && itpl.b == index2)
            || (itpl.b == index1 && itpl.a == index2))
            break;
    }
    if(it == size) {
        itpl.a = index1;
        itpl.b = index2;
        this->listPasangan.push_back(itpl);
    }
}
void Polygon2::lepas_hubung(int index1, int index2) {
    if(index1 >= this->n_titik || index1 < 0
        || index2 >= this->n_titik || index2 < 0)
        return;
    
    // Mencari apakah titik pernah didefinisikan
    int it;
    int size = this->listPasangan.size();
    int_tuple itpl;
    for(it = 0; it < size; it++) {
        itpl = this->listPasangan.at(it);
        if((itpl.a == index1 && itpl.b == index2)
            || (itpl.b == index1 && itpl.a == index2))
            break;
    }
    if(it < size) {
        this->listPasangan.erase(this->listPasangan.begin() + it);
    }
}

// ===
// EXTENDS METHODS
// ===
void Polygon2::Draw(Canvas& canvas) {
    int i;
    int_tuple _itpl;
    int size = this->listPasangan.size();
    
    for(i = 0; i < size; i++) {
        _itpl = this->listPasangan.at(i);
        Line ll(this->listTitik.at(_itpl.a),
            this->listTitik.at(_itpl.b),
            this->warna);
        canvas.DrawLine(ll, this->warna);
    }
}

// ===
// TRANSFORMATION
// ===
void Polygon2::translate(int type, double magnitude) {
    if(type > 3 || type < 0 || magnitude < 0.0)
        return;
    
    std::vector<Point>::iterator it;
    switch(type) {
        case 0: // Up
            for(it = this->listTitik.begin(); it != this->listTitik.end(); ++it) {
                it->y -= magnitude;
            }
            break;
        case 1: // Right
            for(it = this->listTitik.begin(); it != this->listTitik.end(); ++it) {
                it->x += magnitude;
            }
            break;
        case 2: // Down
            for(it = this->listTitik.begin(); it != this->listTitik.end(); ++it) {
                it->y += magnitude;
            }
            break;
        case 3: // Left
            for(it = this->listTitik.begin(); it != this->listTitik.end(); ++it) {
                it->x -= magnitude;
            }
            break;
        default:
            break;
    }
}
void Polygon2::scale(double magnitude) {
    if(magnitude < 0.0)
        return;
    
    double _x, _y, _temp;
    int it;
    int size = this->listTitik.size();
    
    // Get minimum of x
    _x = 9999;
    for(it = 0; it < size; it++) {
        _temp = this->listTitik.at(it).x;
        if(_x > _temp) _x = _temp;
    }
    // Get minimum of y
    _y = 9999;
    for(it = 0; it < size; it++) {
        _temp = this->listTitik.at(it).y;
        if(_y > _temp) _y = _temp;
    }
    
    // Translate
    std::vector<Point>::iterator i;
    for(i = this->listTitik.begin(); i != this->listTitik.end(); ++i) {
        i->x -= _x;
        i->y -= _y;
    }
    
    // Factoring
    for(i = this->listTitik.begin(); i != this->listTitik.end(); ++i) {
        i->x *= magnitude;
        i->y *= magnitude;
    }
    
    // Last translate
    for(i = this->listTitik.begin(); i != this->listTitik.end(); ++i) {
        i->x += _x;
        i->y += _y;
    }
}
