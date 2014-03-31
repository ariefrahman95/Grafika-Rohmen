#ifndef PEMANDANGAN_HPP
#define PEMANDANGAN_HPP

#include "Drawable.hpp"
#include "Polygon.hpp"

class Pemandangan: public Drawable {
    private:
        Polygon2 * pemandangan, * jalan, * marka_jalan;
        int marka_y, iteration;
        
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
        
        // =====================================================================
        // METHODS
        // =====================================================================
        void Update();
};

#endif /* PEMANDANGAN_HPP */