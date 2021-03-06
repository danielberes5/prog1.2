#include "frakablak.h"

FrakAblak::FrakAblak(double a, double b, double c, double d,
                     int szelesseg, int iteraciosHatar, QWidget *parent)
                         : QMainWindow(parent)
{
    setWindowTitle("Mandelbrot halmaz");

    int magassag = (int)(szelesseg * ((d-c)/(b-a)));

    setFixedSize(QSize(szelesseg, magassag));
    fraktal= new QImage(szelesseg, magassag, QImage::Format_RGB32);

    mandelbrot = new FrakSzal(a, b, c, d, szelesseg, magassag, iteraciosHatar, this);
    mandelbrot->start();

}

FrakAblak::~FrakAblak()
{
    delete fraktal;
    delete mandelbrot;
}

void FrakAblak::paintEvent(QPaintEvent*) {
    QPainter qpainter(this);
    qpainter.drawImage(0, 0, *fraktal);
    qpainter.end();
}

void FrakAblak::vissza(int magassag, int *sor, int meret, int hatar)
{
    for(int i=0; i<meret; ++i) {
        //        QRgb szin = qRgb(0, 255-sor[i], 0);
        QRgb szin;
        if(sor[i] == hatar)
            szin = qRgb(0,0,0);
        else
            szin = qRgb(
                    255-sor[i],
                    255-sor[i]%64,
                    255-sor[i]%16 );

        fraktal->setPixel(i, magassag, szin);
    }
    update();
}