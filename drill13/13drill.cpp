#include "Simple_window.h"
#include "Graph.h"

int main(){
	using namespace Graph_lib;
	Simple_window win {Point{100,100},1000,800,"jajajaj"};

	Lines grid;
	int grid_max = 800;
    int grid_size = 100;
    for (int i = grid_size; i<=grid_max; i+=grid_size) {
        grid.add(Point(i,0),Point(i,grid_max));
        grid.add(Point(0,i),Point(grid_max,i));
    }
    win.attach(grid);
    Vector_ref<Rectangle> rectangles;
    for(int i=0;i<800;i+=100){
    	rectangles.push_back(new Rectangle(Point{i,i},grid_size,grid_size));
    	rectangles[rectangles.size()-1].set_fill_color(Color::red);
    	win.attach(rectangles[rectangles.size()-1]);
    }

    Image kep1(Point(0,200),"badge.jpg");
    kep1.set_mask(Point(0,200), 200, 200);
    win.attach(kep1);

    Image kep2(Point(400,200),"badge.jpg");
    kep2.set_mask(Point(0,200), 200, 200);
    win.attach(kep2);

    Image kep3(Point(400,600),"badge.jpg");
    kep3.set_mask(Point(0,200), 200, 200);
    win.attach(kep3);
	win.wait_for_button();

    Image papo(Point(0,0),"papo.jpg");
    papo.set_mask(Point(200,0),100,100);
    win.attach(papo);
    for (int i = 0; i < 8; ++i)
    {
    	for (int j = 0; j < 8; ++j)
    	{
    		win.wait_for_button();
    		if (j < 7) papo.move(100,0);
    		else papo.move(-700,100);
    	}
    }

}