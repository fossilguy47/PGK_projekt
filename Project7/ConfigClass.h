#ifndef __ConfigClass__
#define __ConfigClass__

#include "GUIMyFrame.h"

class ConfigClass
{
private:
    GUIMyFrame* MainWindow;   // wskaznik do glownego okna aplikacji
public:
    ConfigClass(GUIMyFrame* wnd);
};

#endif
