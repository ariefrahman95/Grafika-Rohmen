#ifndef PEMANDANGAN_HPP
#define PEMANDANGAN_HPP

#include "Drawable.hpp"
#include "Polygon.hpp"

class Pemandangan: public Drawable {
    private:
        Polygon2 * pemandangan, * jalan;
        
    public:
        // =====================================================================
        // CONSTRUCTOR, DESTRUCTOR, COPY CONSTRUCTOR
        // =====================================================================
        Pemandangan();
        virtual ~Pemandangan();
        
        // =====================================================================
        // EXTENDS METHOD
        // =====================================================================
        void Draw(Canvas& /* canvas */);
};

#endif /* PEMANDANGAN_HPP */