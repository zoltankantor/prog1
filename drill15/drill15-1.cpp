
/*
	g++ drill15-1.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill15-1 `fltk-config --ldflags --use-images` -std=c++17
*/

#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"
double one (double x) { return x; }
double slope (double x) { return x/2; }
double square (double x) { return x * x; }
double sl_cos (double x) { return cos(x) + slope(x); }





int main() 
try {

	int win_x_max = 600;
	int win_y_max = 600;

	using namespace Graph_lib;

	Simple_window win{Point{100,100}, win_x_max, win_y_max, "Function graphs"};


	
	int orig_x = win_x_max/2;
	int orig_y = win_y_max/2;

	Point orig {orig_x, orig_y};

	int axis_x_length = 400, axis_y_length = 400;
	int axis_scale = 20;
	double xscale = 20, yscale = 20;

	Axis x {Axis::x, Point{orig_x - axis_x_length / 2, orig_y}, axis_x_length, axis_x_length / axis_scale, "1 == 20 pixels"};
	Axis y {Axis::y, Point{orig_x , orig_y + axis_y_length / 2}, axis_y_length, axis_y_length / axis_scale, "1 == 20 pixels"};
	x.set_color(Color::red);
	y.set_color(Color::red);


	
	double rmin = -10;
	double rmax = 11;

	int points = 400;


	
	Function vertical_line {one, rmin, rmax, orig, points, xscale, yscale};

	
	Function slope_line {slope, rmin, rmax, orig, points, xscale, yscale};
	Text slope_line_label {Point{slope_line.point(0).x, slope_line.point(0).y - 10}, "x/2"};
		
	
	Function sqr {square, rmin, rmax, orig, points, xscale, yscale};
		
	
	Function cosin {cos, rmin, rmax, orig, points, xscale, yscale};
	cosin.set_color(Color::blue);
		
	
	Function slope_cosin {sl_cos, rmin, rmax, orig, points, xscale, yscale};



	win.attach(x);
	win.attach(y);
	win.attach(vertical_line);
	win.attach(slope_line);
	win.attach(slope_line_label);
	win.attach(sqr);
	win.attach(cosin);
	win.attach(slope_cosin);



	win.wait_for_button();





} catch (exception& e) {
	cerr << e.what() << endl;
} catch (...) {
	cerr << "Error" << endl;
}
