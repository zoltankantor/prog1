#include "Lines_window.h"
#include "Graph.h"
#include "GUI.h"

int main()
{

	using namespace Graph_lib;
    Lines_window win{Point{100,100}, 1200, 600, "Vector_ref"};
    return gui_main();
}