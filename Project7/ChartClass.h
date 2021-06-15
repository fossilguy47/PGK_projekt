#ifndef __ChartClass__
#define __ChartClass__
#include <memory>
#include <vector>
#include "ConfigClass.h"

class Matrix;
class Vector;

class ChartClass
{
private:
    int _w, _h;
    int plot_w, plot_h;
    float f_max, f_min;
    std::shared_ptr<ConfigClass> cfg;
    std::vector<Segment> loaded_data;
    std::vector<float> valueGrid;
public:
    ChartClass(std::shared_ptr<ConfigClass> c, int w = 600, int h = 400, std::vector<Segment> data=std::vector<Segment>());
    Matrix createTransformationMatrix();
    void Draw(wxDC* dc);
    double getFunctionValue(double x, double y);
    void transformVector(Vector& v);
    void drawLine(wxDC* dc, Vector p0, Vector p1);
    void drawAxes(wxDC* dc);
    void initializeValueGrid();
    void drawContourMap(wxDC* dc);
    void drawChart(wxDC* dc);
    void drawValueBar(wxDC* dc);
    std::vector<float> Get_valueGrid() { return valueGrid; }
    float Get_f_max() { return f_max; }
    float Get_f_min() { return f_min; }
    
};

#endif