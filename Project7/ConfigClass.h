#ifndef __ConfigClass__
#define __ConfigClass__

#include "GUIMyFrame.h"

class ConfigClass
{
private:
    GUIMyFrame* MainWindow;
    bool is_contour = false;
    double x0, y0, x1, y1, z0, z1;
    double x_start, x_stop;
    double y_start, y_stop;
    double alpha, beta, gamma;
    int f_type;

public:
    ConfigClass(GUIMyFrame* wnd);
    bool Get_contour() { return is_contour; };
    void Set_contour(bool value) { is_contour = value; };
    double Get_x_start() { return x_start; };
    void   Set_x_start(double v) { x_start = v; };
    double Get_x_stop() { return x_stop; };
    void   Set_x_stop(double v) { x_stop = v; };
    double Get_y_start() { return y_start; };
    void   Set_y_start(double v) { y_start = v; };
    double Get_y_stop() { return y_stop; };
    void   Set_y_stop(double v) { y_stop = v; };
    void Set_Alpha(int a) { alpha = a; };
    void Set_Beta(int b) { beta = b; };
    void Set_Gamma(int c) { gamma = c; };
    double Get_x0() { return x0; };
    void   Set_x0(float v) { x0 = v; };
    double Get_y0() { return y0; };
    void   Set_y0(float v) { y0 = v; };
    double Get_z0() { return z0; };
    void   Set_z0(float v) { z0 = v; };
    double Get_x1() { return x1; };
    void   Set_x1(float v) { x1 = v; };
    double Get_y1() { return y1; };
    void   Set_y1(float v) { y1 = v; };
    double Get_z1() { return z1; };
    void   Set_z1(float v) { z1 = v; };
    int    Get_f_type() { return f_type; };
    void   set_f_type(int i) { f_type = i; };

};

#endif
