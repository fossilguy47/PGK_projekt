#ifndef __ConfigClass__
#define __ConfigClass__

#include "GUIMyFrame.h"

class ConfigClass
{
private:
    GUIMyFrame* MainWindow;
    bool is_contour = false;
public:
    ConfigClass(GUIMyFrame* wnd);
    bool Get_contour() { return is_contour; };
    void Set_contour(bool value) { is_contour = value; };
};

#endif
