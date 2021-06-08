#include <wx/dc.h>
#include "ChartClass.h"
#include "vecmat.h"
#include <cmath>

#define PI 3.14159

struct Point
{
    double mX, mY, mZ;
    Point(double x = 0., double y = 0., double z = 0.) : mX(x), mY(y), mZ(z) {}
    Point& operator=(const Point& other)
    {
        mX = other.mX;
        mY = other.mY;
        mZ = other.mZ;
        return *this;
    }
    void operator()(double x, double y, double z) { mX = x; mY = y; mZ = z; }
};

struct Segment {
	Point begin, end;
	Segment(Point begin_point, Point end_point) : begin(begin_point), end(end_point){}
};

//struct Segment
//{
//    Point mA, mB, mC;
//    Segment() : mA(), mB(), mC() {}
//    Segment(Point A, Point B, Point C=Point(0,0,0)) : mA(A), mB(B), mC(C) {}
//    double sumZ() const
//    {
//        return mA.mZ + mB.mZ + mC.mZ;
//    }
//};


ChartClass::ChartClass(std::shared_ptr<ConfigClass> c, int w, int h) : _w(w), _h(h) 
{
	cfg = std::move(c);
	initializeValueGrid();
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
	double Tx, Ty, Tz, Rx, Ry, Rz, Sx, Sy, Sz;
	//ustawienie odpowiednich wartosci parametrow

	////TU WSTAWIĆ PRAWIDŁOWE PARAMETRY
	Tx = 0.0;
	Ty = 0.0;
	Tz = 2.0;
	Rx = cfg->Get_x_rot() * 360.0 / 100.0;
	Ry = cfg->Get_y_rot() * 360.0 / 100.0;
	Rz = cfg->Get_z_rot() * 360.0 / 100.0;
	Sx = (cfg->Get_zoom()/50.0) / 100.0;
	Sy = (cfg->Get_zoom() / 50.0) / 100.0;
	Sz = (cfg->Get_zoom() / 50.0) / 100.0;

	//macierze przeksztalcen odpowiednio translacji, rotacji, skalowania
	Matrix T, R, S;
	//macierz translacji, T[3][3] juz wypelnione
	T.data[0][0] = 1;
	T.data[1][1] = 1;
	T.data[2][2] = 1;
	T.data[0][3] = Tx;
	T.data[1][3] = -Ty;
	T.data[2][3] = Tz;
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
		return (x * x + y * y) / 50;
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
		return 50*sin((x * x + y * y)/500);
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
	Vector p0, x1, y1, z1;
	//Ustawienie punktu p0owego i koncowego odcinka
	p0.Set(0,0,0);
	x1.Set(150,0,0);
	y1.Set(0, 150, 0);
	z1.Set(0, 0, 200);
	drawLine(dc, p0, x1);
	drawLine(dc, p0, y1);
	drawLine(dc, p0, z1);
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
}

/*void ChartClass::Scale_valueGrid()
{
	double x0 = cfg->Get_x0();
	double x1 = cfg->Get_x1();
	double y0 = cfg->Get_y0();
	double y1 = cfg->Get_y1();
	// skalowanie mapy konturowej
	// kiedy długość > szerokość
	if (x1 - x0 > y1 - y0)
	{
		plot_w = 500;
		plot_h = static_cast<int>((y1 - y0) / (x1 - x0) * plot_w);
	}
	// kiedy szerokość > długość
	else if (x1 - x0 < y1 - y0)
	{
		plot_h = 500;
		plot_w = static_cast<int>((x1 - x0) / (y1 - y0) * plot_h);
	}
	// kiedy długość == szerokość
	else
	{
		plot_w = 500;
		plot_h = 500;
	}
}*/

void ChartClass::initializeValueGrid()
{
	valueGrid.clear();
	//Scale_valueGrid();
	double x0 = cfg->Get_x0();
	double x1 = cfg->Get_x1();
	double y0 = cfg->Get_y0();
	double y1 = cfg->Get_y1();
	if (x1 - x0 > y1 - y0)
	{
		plot_w = 500;
		plot_h = static_cast<int>((y1 - y0) / (x1 - x0) * plot_w);
	}
	// kiedy szerokość > długość
	else if (x1 - x0 < y1 - y0)
	{
		plot_h = 500;
		plot_w = static_cast<int>((x1 - x0) / (y1 - y0) * plot_h);
	}
	// kiedy długość == szerokość
	else
	{
		plot_w = 500;
		plot_h = 500;
	}
	double x_step = (cfg->Get_x1() - cfg->Get_x0()) / (plot_w - 1.0);
	double y_step = (cfg->Get_y1() - cfg->Get_y0()) / (plot_h - 1.0);
	z_min = z_max = getFunctionValue(cfg->Get_x0(), cfg->Get_y0());
	for (int i = 0; i < plot_h; i++) 
	{
		for (int j = 0; j < plot_w; j++)
		{
			float value = getFunctionValue(cfg->Get_x0() + i * x_step, cfg->Get_y0() + j * y_step);
			/* progowanie wartości (na razie okomentowane, by wychodziły wartości
				f_min i fmax nieograniczone przez z0 i z1)*/
			/*if (value > cfg->Get_z1())
			{
				valueGrid.push_back(cfg->Get_z1());
			}
			else if (value < cfg->Get_z0())
			{
				valueGrid.push_back(cfg->Get_z0());
			}
			else
			{
				valueGrid.push_back(value);
			}*/
			valueGrid.push_back(value);
			z_max = z_max < value ? value : z_max;
			z_min = z_min > value ? value : z_min;
		}
	}
}


void ChartClass::drawContourMap(wxDC *dc)
{

	initializeValueGrid();
	wxBitmap bitmap;
	wxImage image;
	bitmap.Create(plot_w, plot_h, 24);
	image.Create(plot_w, plot_h);

	dc->Clear();
	wxMemoryDC memDC;
	memDC.SelectObject(bitmap);
	memDC.Clear();
	memDC.SetPen(*wxBLACK_PEN);
	memDC.SetBrush(*wxWHITE_BRUSH);
	memDC.SetBackground(*wxWHITE_BRUSH);
	memDC.DrawRectangle(20, 20, plot_w, plot_h);
	memDC.SetClippingRegion(wxRect(20, 20, plot_w, plot_h));
	
	double f_min = valueGrid[0], f_max = valueGrid[0];
	for (int i = 0; i < plot_h; i++)
		for (int j = 0; j < plot_w; j++)
		{
			f_min = valueGrid[plot_w*i + j] < f_min ? valueGrid[plot_w*i + j] : f_min;
			f_max = valueGrid[plot_w*i + j] > f_max ? valueGrid[plot_w*i + j] : f_max;
		}

	// część odpowiedzialna za kolorowanie mapy
	unsigned char* pixels = image.GetData();
	for (int i = 0; i < plot_h; i++)
	{
		for (int j = 0; j < plot_w; j++)
		{
			const float color = (valueGrid[plot_w*i + j] - f_min) / (f_max - f_min);
			const int it = i * plot_w * 3 + j * 3;
			pixels[it] = static_cast<unsigned char> (color * 255);
			pixels[it + 1] = 0;
			pixels[it + 2] = static_cast<unsigned char> ((1.0 - color) * 255);
		}
	}

	const wxBitmap colorMap(image, 24);
	memDC.DrawBitmap(colorMap, 0, 0);

	// kontury (póki co ustawione na 5 poziomic)
	//dc->SetPen(wxPen(*wxBLACK_PEN));
	int NoLevels = 5;
	for (int i = 0; i < NoLevels; i++)
	{
		float threshold = f_min + (i + 1.0) * (f_max - f_min) / (NoLevels + 1.0);

		for (int x = 0; x < plot_w; x++)
			for (int y = 0; y < plot_h; y++)
				if (valueGrid[plot_w*y + x] > threshold)
				{
					for (int a = -1; a <= 1; a++)
						for (int b = -1; b <= 1; b++)
							if (a && b && (a + y >= 0) && (b + x >= 0) && (a + y < plot_h) && (b + x < plot_w) &&
								(valueGrid[plot_w*(a + y)+b + x] < threshold))
								memDC.DrawPoint(x, y);
				}
	}
	dc->Blit(20, 20, plot_w, plot_h, &memDC, 0, 0);
}

void ChartClass::drawChart(wxDC* dc)
{
	double step = 2;
	double x0 = cfg->Get_x0();
	double x1 = cfg->Get_x1();
	double y0 = cfg->Get_y0();
	double y1 = cfg->Get_y1();
	double z_range = z_max - z_min;
	int i, j;
	for (i = 0; i < (x1-x0)/step ; i++)
	{
		for (j = 0; j < (y1 - y0) / step; j++)
		{
			Vector p0, p1, p2;
			//Ustawienie punktu początkowego i koncowego odcinka
			double v0 = getFunctionValue(x0 + step * i, y0 + step * j);
			double v1 = getFunctionValue(x0 + step * (i + 1), y0 + step * j);
			double v2 = getFunctionValue(x0 + step * i, y0 + step * (j + 1));
			dc->SetPen(wxPen(RGB(255 * (v0 - z_min) / z_range, 0, 255 - 255 * (v0-z_min) / z_range)));
			p0.Set(x0 + step * i, y0 + step * j, v0);
			p1.Set(x0 + step * (i+1), y0 + step * j, v1);
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
		//Ustawienie punktu początkowego i koncowego odcinka
		p0.Set(x0 + step * i, y0 + step * j_max, getFunctionValue(x0 + step * i, y0 + step * j_max));
		p1.Set(x0 + step * (i + 1), y0 + step * j_max, getFunctionValue(x0 + step * (i + 1), y0 + step * j_max));
		//Rysowanie połączenia w prawym i dolnym punktem
		drawLine(dc, p0, p1);
	}
	for (j = 0; j < (y1 - y0) / step; j++)
	{
		Vector p0, p1;
		//Ustawienie punktu początkowego i koncowego odcinka
		p0.Set(x0 + step * i_max, y0 + step * j, getFunctionValue(x0 + step * i_max, y0 + step * j));
		p1.Set(x0 + step * i_max, y0 + step * (j + 1), getFunctionValue(x0 + step * i_max, y0 + step * (j+1)));
		//Rysowanie połączenia w prawym i dolnym punktem
		drawLine(dc, p0, p1);
	}
}


