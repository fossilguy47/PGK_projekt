#ifndef __ChartClass__
#define __ChartClass__

#include <memory>
#include "ConfigClass.h"

class Matrix;

class ChartClass
{
private:
    std::shared_ptr<ConfigClass> cfg;
    int _w, _h;
    void drawLine2d(wxDC* dc, Matrix t, double x1, double y1, double x2, double y2);
    void drawAxis(wxDC* dc, Matrix t);
public:
    ChartClass(std::shared_ptr<ConfigClass> c, int w = 600, int h = 400);

    void Draw(wxDC* dc);  // rysuje wykres

};

#endif