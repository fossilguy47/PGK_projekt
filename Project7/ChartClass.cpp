#include <wx/dc.h>
#include <memory>
#include "ChartClass.h"
#include "vecmat.h"

ChartClass::ChartClass(std::shared_ptr<ConfigClass> c, int w, int h) : _w(w), _h(h) {
	cfg = std::move(c);
}

void ChartClass::Draw(wxDC* dc) {
	dc->SetBackground(wxBrush(RGB(255, 255, 255)));
	dc->Clear();
	dc->SetPen(wxPen(RGB(0, 0, 0)));
	if (cfg->Get_contour()) dc->DrawText("KONTUROWA", wxPoint(100,100));
	else dc->DrawText("NIEKONTUROWA", wxPoint(100,100));
}

void ChartClass::drawLine2d(wxDC* dc, Matrix t, double x1, double y1, double x2, double y2) {

}

void ChartClass::drawAxes(wxDC* dc, Matrix t) {

}

