/**
 * Nama/NIM  : Setyo Legowo/13511071
 * Tanggal   : 30 Maret 2014
 * File      : polygon.hpp
 * Deskripsi : Polygon merupakan bentuk dari bidang yang dapat didefinisikan
 *             dengan jumlah minimal 3 titik.
 *             Polygon ini tidak dapat menjamin bahwa dapat membentuk polygon
 *             tertutup. Harus dipastikan oleh pengguna kelas ini sendiri.
 *             
 */

/**
 *
 * @author Setyo Legowo/13511071
 * @date 2014/03/30 21:00
 *
 */

#ifndef POLYGON_HPP
#define POLYGON_HPP
 
#include "Point.hpp"
#include <vector>

typedef struct {
    int a;
    int b;
} int_tuple;

class Polygon {
    private:
        int n_titik;
        std::vector<Point> listTitik;
        std::vector<int_tuple> listPasangan;
        
    public:
        // =====================================================================
        // CONSTRUCTOR, DESTRUCTOR, COPY CONSTRUCTOR
        // =====================================================================
        /**
         * Konstruktor dari bidang polygon. Pada konstruktor titik akan
         * didefinisikan terlebih dahulu. Secara default semua titik yang
         * didefinisikan akan berada di posisi (0,0) dan titak terhubung.
         * @param int Jumlah titik yang akan digunakan untuk membentuk polygon
         */
        Polygon(int /* jumlah_titik */);
        /**
         * Destruktor dari bidang polygon. Diupayakan akan membersihkan memory.
         */
        ~Polygon();
        
        /**
         * @param Polygon objek polygon yang akan di "deep copy"
         */
        Polygon(const Polygon&);
        /**
         * @param Polygon objek polygon yang akan di "shallow copy"
         */
        Polygon& operator=(const Polygon&);
        
        // =====================================================================
        // METHODS
        // =====================================================================
        /**
         * Mendefinisikan posisi dari anggota titik terdefinisi.
         * Jika indeks tidak terdefinisi maka pengesetan posisi tidak dilakukan
         * @param int Indeks titik yang akan didefinisikan
         * @param int Definisikan titik (X)
         * @param int Definisikan titik (Y)
         */
        void define(int /* index */, double /* point x */, double /* point y */);
        
        /**
         * Fungsi yang nantinya akan menggunakan fungsi 'define(int, double, double)'
         * @param int Indeks titik yang akan didefinisikan
         * @param Point Definisikan titik
         */
        void define(int /* index */, const Point& /* point */);
        
        /**
         * Mendefinisikan titik-titik yang ingin terhubung.
         * @param int Indeks pertama
         * @param int Indeks kedua
         */
        void hubung(int /* index 1*/, int /* index 2 */);
        
        // =====================================================================
        // TRANSFORMATION METHODS
        // =====================================================================
        /**
         * Salah satu bentuk transformasi yang melakukan pergesaran bidang polygon
         * @param int Tipe arah perpindahan: 0=>Up, 1=>Right, 2=>Down, 3=>Left
         */
        void translate(int /* type */);
        
        /**
         * Salah satu bentuk transformasi yang melakukan perubahan ukuran dari polygon
         * @param int Tipe pembesaran atau pengecilan: 0=>Memperkecil, 1=>Membesar
         * @param double Besar pembesaran yang akan dilakukan. Masukan: {x>0}
         */
        void scale(int /* type */, double /* magnitude */);
        
        /**
         * Salah satu bentuk transformasi yang melakukan pemutaran bidang
         * @param double Besar pembesaran yang akan dilakukan. Masukan: {x>0}
         */
        void rotate(double /* magnitude */);
};

#endif /* POLYGON_HPP */