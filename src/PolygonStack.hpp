/**
 * Nama/NIM  : Setyo Legowo/13511071
 * Tanggal   : 30 Maret 2014
 * File      : PolygonStack.hpp
 * Deskripsi : Polygon merupakan bentuk dari bidang yang dapat didefinisikan
 *             dengan jumlah minimal 3 titik.
 *             Polygon ini tidak dapat menjamin bahwa dapat membentuk polygon
 *             tertutup. Harus dipastikan oleh pengguna kelas ini sendiri.
 *             Variasi dari polygon yang sebelumnya.
 *
 */

/**
 *
 * @author Setyo Legowo/13511071
 * @date 2014/03/30 22:00
 *
 */

#ifndef POLYGONSTACK_HPP
#define POLYGONSTACK_HPP
 
#include "Point.hpp"
#include <cstdlib>
#include <vector>

class PolygonStack {
    private:
        int n_titik;
        std::vector<Point> listTitikLeft;
        std::vector<Point> listTitikRight;
        
    public:
        // =====================================================================
        // CONSTRUCTOR, DESTRUCTOR, COPY CONSTRUCTOR
        // =====================================================================
        /**
         * Konstruktor dari bidang polygon. Pada konstruktor titik tidak
         * didefinisikan terlebih dahulu.
         */
        PolygonStack();
        /**
         * Destruktor dari bidang polygon. Diupayakan akan membersihkan memory.
         */
        ~PolygonStack();
        
        /**
         * @param Polygon objek polygon yang akan di "deep copy"
         */
        PolygonStack(const PolygonStack&);
        /**
         * @param Polygon objek polygon yang akan di "deep copy"
         */
        PolygonStack& operator=(const PolygonStack&);
        
        // =====================================================================
        // METHODS
        // =====================================================================
        /**
         * Mendefinisikan posisi dari anggota titik terdefinisi. Titik akan
         * di konstruktsi oleh method.
         * @param int Definisikan titik (X) titik kiri
         * @param int Definisikan titik (Y) titik kiri
         * @param int Definisikan titik (X) titik kanan
         * @param int Definisikan titik (Y) titik kanan
         */
        void push(double /* point x left */, double /* point y left */,
                  double /* point x right */, double /* point y right */);
        
        /**
         * Mendefinisikan posisi dari anggota titik terdefinisi. Titik akan
         * di konstruktsi (lagi) oleh method.
         * @param Point Definisikan titik kiri
         * @param Point Definisikan titik kanan
         */
        void push(const Point& /* point left */, const Point& /* point right */);
        
        /**
         * Mengambil kembali posisi titik akibat pop stack
         * @param Point Output dari pop titik kiri. Dapat didefinisikan sebagai null
         * @param Point Output dari pop titik kanan. Dapat didefinisikan sebagai null
         */
        void pop(Point * /* point 1 */, Point * /* point 2 */);
        
        /**
         * Mengambil kembali posisi titik akibat pop stack.
         * Sama seperti pop(Point*, Point*) namun point akan didekstruksi di dalam
         * method ini.
         */
        void pop();
        
        // =====================================================================
        // TRANSFORMATION METHODS
        // =====================================================================
        /**
         * Salah satu bentuk transformasi yang melakukan pergesaran bidang polygon
         * @param int Tipe arah perpindahan: 0=>Up, 1=>Right, 2=>Down, 3=>Left
         * @param double Besar translasi polygon
         */
        void translate(int /* type */, double /* magnitude */);
        
        /**
         * Salah satu bentuk transformasi yang melakukan perubahan ukuran dari polygon
         * @param double Besar pembesaran yang akan dilakukan. Masukan: {x>0}
         * Jika x < 1 maka akan memperkecil polygon, jika x > 1 maka memperbesar polygon
         */
        void scale(double /* magnitude */);
};

#endif /* POLYGONSTACK_HPP */