/**
 * Nama/NIM  : Setyo Legowo/13511071
 * Tanggal   : 30 Maret 2014
 * File      : PolygonStack.cpp
 * Deskripsi : Pendefinisian penggunaan PolygonStack.hpp
 */

#include "PolygonStack.hpp"

PolygonStack::PolygonStack() {
    this->n_titik = 0;
}
PolygonStack::~PolygonStack() {
    this->n_titik = 0;
    this->listTitikLeft.clear();
    this->listTitikRight.clear();
}
PolygonStack::PolygonStack(const PolygonStack& pol) {
    int it;
    this->n_titik = pol.n_titik;
    
    this->listTitikLeft.clear();
    for(it = 0; it < this->n_titik; it++) {
        //Point p(pol.listTitikLeft.at(it));
        this->listTitikLeft.push_back(Point(pol.listTitikLeft.at(it)));
    }
    this->listTitikRight.clear();
    for(it = 0; it < this->n_titik; it++) {
        //Point p(pol.listTitikRight.at(it));
        this->listTitikRight.push_back(Point(pol.listTitikRight.at(it)));
    }
}
PolygonStack& PolygonStack::operator=(const PolygonStack& pol) {
    int it;
    this->n_titik = pol.n_titik;
    
    this->listTitikLeft.clear();
    for(it = 0; it < this->n_titik; it++) {
        // Point p(pol.listTitikLeft.at(it));
        this->listTitikLeft.push_back(Point(pol.listTitikLeft.at(it)));
    }
    this->listTitikRight.clear();
    for(it = 0; it < this->n_titik; it++) {
        // Point p(pol.listTitikRight.at(it));
        this->listTitikRight.push_back(Point(pol.listTitikRight.at(it)));
    }
    
    return *this;
}

// ===
// METHODS
// ===
void PolygonStack::push(double x_left, double y_left,
                  double x_right, double y_right) {
    if(x_left < 0 || y_left < 0 || x_right < 0 || y_right < 0)
        return;
    
    // Point p_l(x_left, y_left);
    this->listTitikLeft.push_back(Point(x_left, y_left));
    // Point p_r(x_right, y_right);
    this->listTitikRight.push_back(Point(x_right, y_right));
    
    this->n_titik++;
}
void PolygonStack::push(const Point& left, const Point& right) {
    push(left.x, left.y, right.x, right.y);
}
void PolygonStack::pop(Point * p_1, Point * p_2) {
    if(this->listTitikLeft.empty() || this->listTitikRight.empty() || this->n_titik <= 0)
        return;
    
    if(p_1 != NULL) *p_1 = this->listTitikLeft.back();
    this->listTitikLeft.pop_back();
    if(p_2 != NULL) *p_2 = this->listTitikRight.back();
    this->listTitikRight.pop_back();
    
    this->n_titik--;
}
void PolygonStack::pop() {
    pop(NULL, NULL);
}

// ===
// TRANSFORMATION
// ===
void PolygonStack::translate(int type, double magnitude) {
    if(type > 3 || type < 0 || magnitude < 0.0)
        return;
    
    std::vector<Point>::iterator it;
    switch(type) {
        case 0: // Up
            for(it = this->listTitikLeft.begin(); it != this->listTitikLeft.end(); ++it) {
                it->y -= magnitude;
            }
            for(it = this->listTitikRight.begin(); it != this->listTitikRight.end(); ++it) {
                it->y -= magnitude;
            }
            break;
        case 1: // Right
            for(it = this->listTitikLeft.begin(); it != this->listTitikLeft.end(); ++it) {
                it->x += magnitude;
            }
            for(it = this->listTitikRight.begin(); it != this->listTitikRight.end(); ++it) {
                it->x += magnitude;
            }
            break;
        case 2: // Down
            for(it = this->listTitikLeft.begin(); it != this->listTitikLeft.end(); ++it) {
                it->y += magnitude;
            }
            for(it = this->listTitikRight.begin(); it != this->listTitikRight.end(); ++it) {
                it->y += magnitude;
            }
            break;
        case 3: // Left
            for(it = this->listTitikLeft.begin(); it != this->listTitikLeft.end(); ++it) {
                it->x -= magnitude;
            }
            for(it = this->listTitikRight.begin(); it != this->listTitikRight.end(); ++it) {
                it->x -= magnitude;
            }
            break;
        default:
            break;
    }
}
void PolygonStack::scale(double magnitude) {
    if(magnitude < 0.0)
        return;
    
    double _x, _y, _temp;
    int it;
    int size = this->n_titik;
    
    // Get minimum of x
    _x = 9999;
    for(it = 0; it < size; it++) {
        _temp = this->listTitikLeft.at(it).x;
        if(_x > _temp) _x = _temp;
    }
    for(it = 0; it < size; it++) {
        _temp = this->listTitikRight.at(it).x;
        if(_x > _temp) _x = _temp;
    }
    // Get minimum of y
    _y = 9999;
    for(it = 0; it < size; it++) {
        _temp = this->listTitikLeft.at(it).y;
        if(_y > _temp) _y = _temp;
    }
    for(it = 0; it < size; it++) {
        _temp = this->listTitikRight.at(it).y;
        if(_y > _temp) _y = _temp;
    }
    
    // Translate
    std::vector<Point>::iterator i;
    for(i = this->listTitikLeft.begin(); i != this->listTitikLeft.end(); ++i) {
        i->x -= _x;
        i->y -= _y;
    }
    for(i = this->listTitikRight.begin(); i != this->listTitikRight.end(); ++i) {
        i->x -= _x;
        i->y -= _y;
    }
    
    // Factoring
    for(i = this->listTitikLeft.begin(); i != this->listTitikLeft.end(); ++i) {
        i->x *= magnitude;
        i->y *= magnitude;
    }
    for(i = this->listTitikRight.begin(); i != this->listTitikRight.end(); ++i) {
        i->x *= magnitude;
        i->y *= magnitude;
    }
    
    // Last translate
    for(i = this->listTitikLeft.begin(); i != this->listTitikLeft.end(); ++i) {
        i->x += _x;
        i->y += _y;
    }
    for(i = this->listTitikRight.begin(); i != this->listTitikRight.end(); ++i) {
        i->x += _x;
        i->y += _y;
    }
}















