/**
 * Nama/NIM  : Setyo Legowo/13511071
 * Tanggal   : 30 Maret 2014
 * File      : Polygon.hpp
 * Deskripsi : Polygon merupakan bentuk dari bidang yang dapat didefinisikan
 *             dengan jumlah minimal 3 titik.
 *             Polygon ini tidak dapat menjamin bahwa dapat membentuk polygon
 *             tertutup. Harus dipastikan oleh pengguna kelas ini sendiri.
 *             ASUMSI: Bukan skala cartesian, skala yang digunakan adalah
 *                     skala layar. Titik harus positif dan 0,0 berada di
 *                     kiri atas.
 *             
 */

/**
 *
 * @author Setyo Legowo/13511071
 * @date 2014/03/30 21:00
 * @lastedit 2014/03/31 12:03
 *
 */

#ifndef POLYGON_HPP
#define POLYGON_HPP
 
#include "Point.hpp"
#include "Drawable.hpp"
#include <vector>

typedef struct {
    int a;
    int b;
} int_tuple;

class Polygon2: public Drawable {
    private:
        int n_titik;
        int warna;
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
        Polygon2(int /* jumlah_titik */);
        /**
         * Destruktor dari bidang polygon. Diupayakan akan membersihkan memory.
         */
        virtual ~Polygon2();
        
        /**
         * @param Polygon objek polygon yang akan di "deep copy"
         */
        Polygon2(const Polygon2&);
        /**
         * @param Polygon objek polygon yang akan di "deep copy"
         */
        Polygon2& operator=(const Polygon2&);
        
        // =====================================================================
        // METHODS
        // =====================================================================
        /**
         * Set warna
         * @param int Definisikan warna dalam bentuk bilangan bulat
         */
        void setColor(int /* color */);
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
         * Mengembalikan nilai titik index
         * @param int Indeks titik yang dicari
         */
        Point getT(int /* index*/);
		
         /**
         * Mendefinisikan titik-titik yang ingin terhubung.
         * @param int Indeks pertama
         * @param int Indeks kedua
         */
        void hubung(int /* index 1*/, int /* index 2 */);
        
        /**
         * Menghapus pasangan index titik.
         * @param int Indeks pertama
         * @param int Indeks kedua
         */
        void lepas_hubung(int /* index 1*/, int /* index 2 */);
        
        // =====================================================================
        // EXTENDS METHOD
        // =====================================================================
        void Draw(Canvas& /* canvas */);
        
        // =====================================================================
        // TRANSFORMATION METHODS
        // =====================================================================
        /**
         * Salah satu bentuk transformasi yang melakukan pergesaran bidang polygon
         * @param int Tipe arah perpindahan: 0=>Up, 1=>Right, 2=>Down, 3=>Left
         * @param double besar pergeseran yang diberikan ke polygon
         */
        void translate(int /* type */, double /* magnitude */);
        
        /**
         * Salah satu bentuk transformasi yang melakukan perubahan ukuran dari polygon
         * ASUMSI: Titik akan selalu positif dan titik (0,0) berada di kiri atas
         * @param double Besar pembesaran yang akan dilakukan. Masukan: {x>0}
         * Jika x < 1 maka akan memperkecil polygon, jika x > 1 maka akan
         * memperbesar polygon. {x adalah magnitude}
         */
        void scale(double /* magnitude */);
};

#endif /* POLYGON_HPP */