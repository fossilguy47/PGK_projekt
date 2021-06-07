#ifndef __ChartClass__
#define __ChartClass__

#include <memory>
#include "ConfigClass.h"

class Matrix;
class Vector;
struct Segment;

class ChartClass
{
private:
    std::shared_ptr<ConfigClass> cfg;
    int _w, _h;
public:
    ChartClass(std::shared_ptr<ConfigClass> c, int w = 600, int h = 400);
    Matrix createTransformationMatrix();
    void Draw(wxDC* dc);
    void transformVector(Vector& v);
    void drawLine(wxDC* dc, Vector p0, Vector p1);
    void drawAxes(wxDC* dc);
    void drawContourMap(wxDC* dc);
    void drawChart(wxDC* dc);
    double getFunctionValue(double x, double y);
};

#endif