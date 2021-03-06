#include <wx/dc.h>
#include "ChartClass.h"
#include "vecmat.h"
#include <cmath>

#define PI 3.14159

double shepard(std::vector<Segment> &data, double x, double y, Point &p_min, Point &p_max)
{
	double a = 0;
	double b = 0;

	// punkty, w których znajduje się wartość minimalna (p_min) i maksymalna (p_max) funkcji
	double w_b = (x - p_min.mX) * (x - p_min.mX) + (y - p_min.mY) * (y - p_min.mY);
	double w = 1.f / w_b;
	b += w;
	a += w * p_min.mZ;

	w_b = (x - p_max.mX) * (x - p_max.mX) + (y - p_max.mY) * (y - p_max.mY);
	w = 1.f / w_b;
	b += w;
	a += w * p_max.mZ;

	// wybieramy 20 segmentów (dzielnik)
	unsigned step = data.size() / 20 > 0 ? data.size() / 20 : 1;
	for (unsigned i = 0; i < data.size(); i += step)
	{
		w_b = (x - data[i].begin.mX) * (x - data[i].begin.mX) + (y - data[i].begin.mY) * (y - data[i].begin.mY);
		w = 1.f / w_b;

		b += w;
		a += w * data[i].begin.mZ;

		w_b = (x - data[i].end.mX) * (x - data[i].end.mX) + (y - data[i].end.mY) * (y - data[i].end.mY);
		w = 1.f / w_b;

		b += w;
		a += w * data[i].end.mZ;
	}
	
	return a / b;
}

ChartClass::ChartClass(std::shared_ptr<ConfigClass> c, int w, int h, std::vector<Segment> data) : _w(w), _h(h) 
{
	cfg = std::move(c);
	loaded_data = data;
	if(!cfg->Get_loaded() && !cfg->Get_contour()) 
		initializeValueGrid();
	else
	{
		for (unsigned int i = 0; i < loaded_data.size(); i++)
		{
			f_min = loaded_data[i].begin.mZ < f_min ? loaded_data[i].begin.mZ : f_min;
			f_max = loaded_data[i].begin.mZ > f_max ? loaded_data[i].begin.mZ : f_max;
			f_min = loaded_data[i].end.mZ < f_min ? loaded_data[i].end.mZ : f_min;
			f_max = loaded_data[i].end.mZ > f_max ? loaded_data[i].end.mZ : f_max;
		}
	}
}

Matrix createRotationMatrix(double Rx, double Ry, double Rz) {
	//Macierze rotacji wokół osi X, Y, Z
	Matrix R_X, R_Y, R_Z;
	//Wypelniamy macierze zgodnie ze schematem zaprezentowanym na wykładzie
	R_X.data[0][0] = 1;
	R_X.data[1][1] = cos(Rx * PI / 180);
	R_X.data[1][2] = -sin(Rx * PI / 180);
	R_X.data[2][1] = sin(Rx * PI / 180);
	R_X.data[2][2] = cos(Rx * PI / 180);

	R_Y.data[0][0] = cos(Ry * PI / 180);
	R_Y.data[0][2] = sin(Ry * PI / 180);
	R_Y.data[1][1] = 1;
	R_Y.data[2][0] = -sin(Ry * PI / 180);
	R_Y.data[2][2] = cos(Ry * PI / 180);

	R_Z.data[0][0] = cos(Rz * PI / 180);
	R_Z.data[0][1] = -sin(Rz * PI / 180);
	R_Z.data[1][0] = sin(Rz * PI / 180);
	R_Z.data[1][1] = cos(Rz * PI / 180);
	R_Z.data[2][2] = 1;

	//Zwracamy iloczyn odpowiadający kolejnym transformacjom w 3 wymiarach
	return R_X * R_Y * R_Z;
}

Matrix ChartClass::createTransformationMatrix() {
	//wartosci zmian x y z odpowiednio do translacji, rotacji, skalowania
	double Rx, Ry, Rz, Sx, Sy, Sz;
	//ustawienie odpowiednich wartosci parametrow
	Rx = cfg->Get_x_rot() * 360.0 / 100.0;
	Ry = cfg->Get_y_rot() * 360.0 / 100.0;
	Rz = cfg->Get_z_rot() * 360.0 / 100.0;
	Sx = ((cfg->Get_zoom() + 10.0) / 50.0) / 100.0;
	Sy = ((cfg->Get_zoom() + 10.0) / 50.0) / 100.0;
	Sz = ((cfg->Get_zoom() + 10.0) / 50.0) / 100.0;
	//macierze przeksztalcen odpowiednio translacji, rotacji, skalowania
	Matrix T, R, S;
	//macierz translacji, T[3][3] juz wypelnione
	T.data[0][0] = 1.0;
	T.data[1][1] = 1.0;
	T.data[2][2] = 1.0;
	T.data[0][3] = 0.0;
	T.data[1][3] = 0.0;
	T.data[2][3] = 2.0;
	//uzupelnienie macierzy rotacji przy wykorzystaniu osobnej funkcji
	R = createRotationMatrix(Rx, Ry, Rz);
	//macierz skalowania
	S.data[0][0] = Sx;
	S.data[1][1] = -Sy;
	S.data[2][2] = Sz;

	return T * R * S;
}

void ChartClass::Draw(wxDC* dc) 
{
	dc->SetBackground(wxBrush(RGB(255, 255, 255)));
	dc->Clear();
	dc->SetPen(wxPen(RGB(0, 0, 0)));
	if (cfg->Get_contour())
	{
		drawContourMap(dc);
	}
	else 
	{
		drawAxes(dc);
		drawChart(dc);
	}
}

double ChartClass::getFunctionValue(double x, double y)
{
	auto sign = [](double a) {return a > 0 ? 1 : (a == 0 ? 0 : -1); };
	switch (cfg->Get_f_type())
	{
	case 1:
		return 50 * sin((x * x + y * y) / 500);
		break;
	case 2:
		return (sign(-65 - x) + sign(-35 - x) + sign(-5 - x) + sign(25 - x) + sign(55 - x)) * 10;
		break;
	case 3:
		return x + 2 * y;
		break;
	case 4:
		return (x*y) / exp(pow(0.05 * x, 2) * pow(0.05 * y, 2))/3;
		break;
	default:
		return (x * x + y * y) / 50;
	}
}

void ChartClass::transformVector(Vector& v)
{
	//Macierz transformacji
	Matrix T = createTransformationMatrix();
	Matrix C;
	C.data[0][0] = 1;
	C.data[1][1] = 1;
	C.data[2][2] = 1;
	C.data[0][3] = 0.5;
	C.data[1][3] = 0.5;
	//Przemonozenie obu punktów przez macierze transformacji
	v = T * v;
	//Rzutowanie punktów na płaszczyznę ekranu, "spłaszczenie" osi Z
	v.Set(v.GetX() / v.GetZ(), v.GetY() / v.GetZ(), v.GetZ());
	//Dodatkowa translacja określająca środek ekranu
	v = C * v;
}

void ChartClass::drawLine(wxDC* dc, Vector p0, Vector p1)
{
	transformVector(p0);
	transformVector(p1);
	dc->DrawLine(p0.GetX() * _w, p0.GetY() * _h, p1.GetX() * _w, p1.GetY() * _h);
}

void ChartClass::drawAxes(wxDC* dc) {
	dc->SetBackground(wxBrush(RGB(255, 255, 255)));
	dc->SetTextForeground(wxColour(0,0,0));
	dc->Clear();
	dc->SetPen(wxPen(RGB(0, 0, 0)));
	//Poczatkowy i koncowy punkt odcinka
	Vector p0, x1, y1, z1, arr_x, arr_y, arr_z;
	//Ustawienie punktu poczatku i konca odcinka, rysowanie osi
	p0.Set(0,0,0);
	x1.Set(150,0,0);
	y1.Set(0, 150, 0);
	z1.Set(0, 0, 200);
	drawLine(dc, p0, x1);
	drawLine(dc, p0, y1);
	drawLine(dc, p0, z1);
	arr_x.Set(140, -5, 0);
	arr_y.Set(-5, 140, 0);
	arr_z.Set(-3, 3, 190);
	drawLine(dc, x1, arr_x);
	drawLine(dc, y1, arr_y);
	drawLine(dc, z1, arr_z);
	arr_x.Set(140, 5, 0);
	arr_y.Set(5, 140, 0);
	arr_z.Set(3, -3, 190);
	drawLine(dc, x1, arr_x);
	drawLine(dc, y1, arr_y);
	drawLine(dc, z1, arr_z);
	//Text osi
	dc->SetPen(wxPen(RGB(0, 0, 0)));
	Vector x_text, y_text, z_text;
	x_text.Set(150, -10, 0);
	y_text.Set(-10, 150, 0);
	z_text.Set(10, 0, 200);
	transformVector(x_text);
	transformVector(y_text);
	transformVector(z_text);
	dc->DrawText("X", wxPoint(x_text.GetX() * _w, x_text.GetY() * _h));
	dc->DrawText("Y", wxPoint(y_text.GetX() * _w, y_text.GetY() * _h));
	dc->DrawText("Z", wxPoint(z_text.GetX() * _w, z_text.GetY() * _h));
	//Skala osi
	Vector p;
	for (int i = 25 ; i < 150; i+=25) {
		p.Set(i, 0, 0);
		transformVector(p);
		dc->DrawCircle(wxPoint(p.GetX() * _w, p.GetY() * _h), 1);
		p.Set(i, 5, 0);
		transformVector(p);
		dc->DrawText(wxString::Format(wxT("%d"), i), wxPoint(p.GetX() * _w, p.GetY() * _h));
		p.Set(0, i, 0);
		transformVector(p);
		dc->DrawCircle(wxPoint(p.GetX() * _w, p.GetY() * _h), 1);
		p.Set(-5, i, 0);
		transformVector(p);
		dc->DrawText(wxString::Format(wxT("%d"), i), wxPoint(p.GetX() * _w, p.GetY() * _h));
	}
	for (int i = 50; i <= 200; i += 50) {
		p.Set(0, 0, i);
		transformVector(p);
		dc->DrawCircle(wxPoint(p.GetX() * _w, p.GetY() * _h), 1);
		p.Set(0, 5, i);
		transformVector(p);
		dc->DrawText(wxString::Format(wxT("%d"), i), wxPoint(p.GetX() * _w, p.GetY() * _h));
	}
}

void ChartClass::initializeValueGrid()
{
	valueGrid.clear();
	double x0, x1, y0, y1;
	Point a, b;
	a = b = Point(0,0,0);
	if (cfg->Get_loaded())
	{
		f_min = loaded_data[0].begin.mZ;
		f_max = loaded_data[0].begin.mZ;

		for (unsigned int i = 0; i < loaded_data.size(); i++)
		{
			if (f_min > loaded_data[i].begin.mZ)
			{
				f_min = loaded_data[i].begin.mZ;
				a = loaded_data[i].begin;
			}

			if (f_max < loaded_data[i].begin.mZ)
			{
				f_max = loaded_data[i].begin.mZ;
				b = loaded_data[i].begin;
			}

			if (f_min > loaded_data[i].end.mZ)
			{
				f_min = loaded_data[i].end.mZ;
				a = loaded_data[i].end;
			}

			if (f_max < loaded_data[i].end.mZ)
			{
				f_max = loaded_data[i].end.mZ;
				b = loaded_data[i].end;
			}
		}
	}
	else
	{
		f_min = f_max = getFunctionValue(cfg->Get_x0(), cfg->Get_y1());
	}

	x0 = cfg->Get_x0();
	x1 = cfg->Get_x1();
	y0 = cfg->Get_y0();
	y1 = cfg->Get_y1();

	if (x1 - x0 > y1 - y0)
	{
		plot_w = _h - 100 > 100 ? _h-100 : 200;
		plot_h = static_cast<int>((y1 - y0) / (x1 - x0) * plot_w);
	}
	// kiedy szerokość > długość
	else if (x1 - x0 < y1 - y0)
	{
		plot_h = _h - 100 > 100 ? _h - 100 : 200;
		plot_w = static_cast<int>((x1 - x0) / (y1 - y0) * plot_h);
	}
	// kiedy długość == szerokość
	else
	{
		plot_w = _h - 100 > 100 ? _h - 100 : 200;
		plot_h = _h - 100 > 100 ? _h - 100 : 200;
	}
	double x_step = (x1 - x0) / (plot_w - 1.0);
	double y_step = (y1 - y0) / (plot_h - 1.0);
	for (int i = 0; i < plot_h; i++)
	{
		for (int j = 0; j < plot_w; j++)
		{
			float value = cfg->Get_loaded() ? shepard(loaded_data, x0 + j * x_step, y1 - i * y_step, a, b)
											: getFunctionValue(x0 + j * x_step, y1 - i * y_step);
			valueGrid.push_back(value);
			if (!cfg->Get_loaded())
			{
				f_max = f_max < value ? value : f_max;
				f_min = f_min > value ? value : f_min;
			}
		}
	}
}


void ChartClass::drawContourMap(wxDC *dc)
{
	dc->SetBackground(wxBrush(RGB(255, 255, 255)));
	dc->SetTextForeground(wxColour(0, 0, 0));
	dc->Clear();
	dc->SetPen(*wxBLACK_PEN);

	initializeValueGrid();
	dc->DrawRectangle(wxRect(99, 19, plot_w + 2, plot_h + 2));

	wxBitmap bitmap;
	wxImage image;
	bitmap.Create(plot_w, plot_h, 24);
	image.Create(plot_w, plot_h);
	
	wxMemoryDC memDC;
	memDC.SelectObject(bitmap);
	memDC.SetPen(wxColor(50, 50, 50));
	memDC.SetBrush(*wxWHITE_BRUSH);
	memDC.SetBackground(*wxWHITE_BRUSH);

	unsigned char* pixels = image.GetData();
	for (int i = 0; i < plot_h; i++)
	{
		for (int j = 0; j < plot_w; j++)
		{
			const float color = (valueGrid[plot_w * i + j] - f_min) / (f_max - f_min);
			const int it = i * plot_w * 3 + j * 3;
			pixels[it] = static_cast<unsigned char> (color * 255);
			pixels[it + 1] = 0;
			pixels[it + 2] = static_cast<unsigned char> ((1.0 - color) * 255);
		}
	}

	const wxBitmap colorMap(image, 24);
	memDC.DrawBitmap(colorMap, 0, 0);
	memDC.SetPen(*wxBLACK_PEN);

	// kratka zaprogramowana na wartość pojedynczego kroku
	int x_step = cfg->Get_x_step();
	int y_step = cfg->Get_y_step();
	int w_step = static_cast<int>(plot_w*x_step / (cfg->Get_x1()- cfg->Get_x0()));
	int h_step = static_cast<int>(plot_h*y_step / (cfg->Get_y1() - cfg->Get_y0()));

	dc->SetFont(*wxSMALL_FONT);
	dc->SetPen(*wxBLACK_PEN);
	for (int i = 0; i <= plot_w; i += w_step)
	{
		dc->DrawText(wxString::Format("%10.2f", cfg->Get_x0() + (i / w_step) * x_step), 70 + i, 40 + plot_h);
		dc->DrawLine(100 + i, 20 + plot_h, 100 + i, 30 + plot_h);
		//memDC.DrawLine(i, plot_h - 10, i, plot_h); // krótka kreska
		memDC.DrawLine(i, 0, i, plot_h);
	}
	for (int i = 0; i <= plot_h; i += h_step)
	{
		dc->DrawText(wxString::Format("%10.2f", cfg->Get_y0() + (i / h_step) * y_step), 30, plot_h+13-i);
		dc->DrawLine(89, plot_h+20-i, 99, plot_h+20-i);
		//memDC.DrawLine(0, i, 10, i); / krótka kreska
		memDC.DrawLine(0, plot_h-i, plot_w, plot_h-i);
	}
	dc->Blit(100, 20, plot_w, plot_h, &memDC, 0, 0);
}

void ChartClass::drawChart(wxDC* dc)
{
	double step = 2;
	double x0 = cfg->Get_x0();
	double x1 = cfg->Get_x1();
	double y0 = cfg->Get_y0();
	double y1 = cfg->Get_y1();
	double z_range = f_max - f_min;
	int i, j;
	if (!cfg->Get_loaded()) {
		for (i = 0; i < (x1 - x0) / step; i++)
		{
			for (j = 0; j < (y1 - y0) / step; j++)
			{
				Vector p0, p1, p2;
				//Ustawienie punktu początkowego i koncowego odcinka
				double v0 = getFunctionValue(x0 + step * i, y0 + step * j);
				double v1 = getFunctionValue(x0 + step * (i + 1), y0 + step * j);
				double v2 = getFunctionValue(x0 + step * i, y0 + step * (j + 1));
				dc->SetPen(wxPen(RGB(255 * (v0 - f_min) / z_range, 0, 255 - 255 * (v0 - f_min) / z_range)));
				p0.Set(x0 + step * i, y0 + step * j, v0);
				p1.Set(x0 + step * (i + 1), y0 + step * j, v1);
				p2.Set(x0 + step * i, y0 + step * (j + 1), v2);
				//Rysowanie połączenia w prawym i dolnym punktem
				drawLine(dc, p0, p1);
				drawLine(dc, p0, p2);
			}
		}

		int i_max = i;
		int j_max = j;
		//Dorysowanie skrajnych linii na wykresie
		for (i = 0; i < (x1 - x0) / step; i++)
		{
			Vector p0, p1;
			double v0 = getFunctionValue(x0 + step * i, y0 + step * j_max);
			double v1 = getFunctionValue(x0 + step * (i + 1), y0 + step * j_max);
			//Ustawienie punktu początkowego i koncowego odcinka
			dc->SetPen(wxPen(RGB(255 * (v0 - f_min) / z_range, 0, 255 - 255 * (v0 - f_min) / z_range)));
			p0.Set(x0 + step * i, y0 + step * j_max, v0);
			p1.Set(x0 + step * (i + 1), y0 + step * j_max, v1);
			//Rysowanie połączenia w prawym i dolnym punktem
			drawLine(dc, p0, p1);
		}
		for (j = 0; j < (y1 - y0) / step; j++)
		{
			Vector p0, p1;
			//Ustawienie punktu początkowego i koncowego odcinka
			p0.Set(x0 + step * i_max, y0 + step * j, getFunctionValue(x0 + step * i_max, y0 + step * j));
			p1.Set(x0 + step * i_max, y0 + step * (j + 1), getFunctionValue(x0 + step * i_max, y0 + step * (j + 1)));
			//Rysowanie połączenia w prawym i dolnym punktem
			drawLine(dc, p0, p1);
		}
	}
	else {
		double v_max=loaded_data[0].begin.mZ, v_min = loaded_data[0].begin.mZ;
		for (auto seg : loaded_data) {
			v_max = v_max < seg.begin.mZ ? seg.begin.mZ : v_max;
			v_min = v_min > seg.begin.mZ ? seg.begin.mZ : v_min;
		}		
		Vector p0, p1;
		for (auto seg : loaded_data) {
			p0.Set(seg.begin.mX, seg.begin.mY, seg.begin.mZ);
			p1.Set(seg.end.mX, seg.end.mY, seg.end.mZ);
			dc->SetPen(wxPen(RGB(255 * (p1.GetZ() - v_min) / (v_max - v_min), 0, 255 - 255 * (p1.GetZ() - v_min) / (v_max - v_min))));
			drawLine(dc, p0, p1);
		}
	}
}

// funkcja rysująca legendę kolorów, póki co znajduje się ona po prawej stronie panelu
void ChartClass::drawValueBar(wxDC * dc)
{
	dc->SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
	wxBitmap bitmap;
	wxImage image;
	bitmap.Create(20, _h - 20, 24);
	image.Create(20, _h - 20);

	dc->SetPen(*wxBLACK_PEN);
	// obramowanie
	dc->DrawRectangle(_w - 41, 39, 22, _h - 78);
	dc->DrawLine(_w - 51, 39, _w - 41, 39);
	dc->DrawLine(_w - 51, _h - 40, _w - 41, _h - 40);
	
	dc->DrawText(wxString::Format(wxT("%10.2lf"), Get_f_max()), _w - 125, 30);
	dc->DrawText(wxString::Format(wxT("%10.2lf"), Get_f_min()), _w - 125, _h - 50);
	
	wxMemoryDC memDC;
	memDC.SelectObject(bitmap);
	memDC.SetBrush(*wxWHITE_BRUSH);
	memDC.SetBackground(*wxWHITE_BRUSH);

	// rysowanie legendy
	unsigned char* pixels = image.GetData();
	for (int i = 0; i < _h - 40; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			const float color = static_cast<float>(i) / static_cast<float>(_h - 40);
			const int it = i * 20 * 3 + j * 3;
			pixels[it] = static_cast<unsigned char> ((1.0 - color) * 255);
			pixels[it + 1] = 0;
			pixels[it + 2] = static_cast<unsigned char> (color * 255);
		}
	}
	const wxBitmap colorMap(image, 24);
	memDC.DrawBitmap(colorMap, 0, 0);
	dc->Blit(_w - 40, 40, 20, _h - 80, &memDC, 0, 0);

	dc->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

	// wyświetlanie wzoru funkcji
	if (cfg->Get_loaded())
	{
		dc->DrawText("Funkcja z pliku", 30, _h - 30);
	}
	else
	{
		wxString str = "";
		switch (cfg->Get_f_type())
		{
		case 1:
			str = "f(x,y) = 50sin((x^2 + y^2)/500)";
			break;
		case 2:
			str = "f(x,y) = 10(sgn(-65 - x) + sgn(-35 - x) + sgn(-5 - x) + sgn(25 - x) + sgn(55 - x))";
			break;
		case 3:
			str = "f(x,y) = x + 2y";
			break;
		case 4:
			str = "f(x,y) = 1/3 * xy/e^((0.05x)^2 * (0.05y)^2)";
			break;
		default:
			str = "f(x,y) = (x^2 + y^2)/50";
		}
		dc->DrawText(str, 30, _h - 30);
	}
}



