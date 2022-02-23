#include "Simple_window.h"
#include "Graph.h"

int main(){

	using namespace Graph_lib;

    Point tl {200,100}; 
	Simple_window win {tl,600,400,"Canvas"};

	Polygon poly; 
	poly.add(Point{300,200}); 
	poly.add(Point{350,100}); 
	poly.add(Point{400,200}); 
	poly.set_color(Color::red); 
	poly.set_style(Line_style(Line_style::dashdotdot,5));

	Axis xa {Axis::x, Point{20,300}, 280, 20, "x axis"}; 
	Axis ya {Axis::y, Point{20,300}, 280, 20, "y axis"};
	ya.set_color(Color::white); 
	ya.label.set_color(Color::dark_red);


	Rectangle r {Point{200,200}, 100, 50}; // top left corner, width, height
	r.set_fill_color(Color::yellow); 
	r.set_color(Color::green);

	Text t {Point{350,350}, "Hello world!"};
	t.set_font(Font::helvetica_italic);
	t.set_font_size(30);

	Image ii {Point{700,200},"badge.jpg"};

	Circle c {Point{100,200},50};
	c.set_style(Line_style(Line_style::dot,3));
	Ellipse e {Point{100,200}, 75,25};
	e.set_color(Color::dark_red);
	e.set_style(Line_style(Line_style::dot,3));
	Mark m {Point{100,200},'x'};

	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
	<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,20},oss.str()};
	
	win.attach (poly); 
	win.attach(xa);	
	win.attach(ya);
	win.attach(r);
	win.attach(t);
	win.attach(ii);
	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.attach(sizes);
	win.wait_for_button(); 
	
}