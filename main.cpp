#include <iostream>

#include "shapes.h"

using namespace std;

ShapeList generate_ShapeList() {
    ShapeList sl;

    Circle_p c = make_shared<Circle>("c1", 1);
    EquiTriangle_p e = make_shared<EquiTriangle>("et",2);
    Triangle_p t = make_shared<Triangle>("t1",1,3,3);    

    sl.push_back(c);
    sl.push_back(e);
    sl.push_back(t);

    //smart pointers in list surive list copy
    return sl; 
}

int main() {
    ShapeList sl = generate_ShapeList();

    for(Shape_p shape : sl) {
        cout << "Shape " << shape->get_name()
             << " has area = " << shape->area() << endl;
    }
    cout << endl;

    sl.pop_back(); // destroy last added element: t
    sl.push_back(make_shared<Triangle>("t2", 1,2,4));

    for(Shape_p shape : sl) {
        cout << "Shape " << shape->get_name() << " is ";

        if(Triangle_p tp = shape->is_triangle())  {
            cout << (tp->is_valid_triangle() ? "a valid" : "an invalid")
                 << " triangle." << endl;
        } else {
            cout << "not a triangle" << endl;
        }
    }   

    return 0;
}

/* Provides output: 
 *
 *  Shape c1 has area = 3.14159
 *  Shape et has area = 1.73205
 *  Shape t1 has area = 1.47902
 *
 *  Shape c1 is not a triangle
 *  Shape et is a valid triangle.
 *  Shape t2 is an invalid triangle.
 * 
*/