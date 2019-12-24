#include <iostream>

#include "shapes.h"

using namespace std;

ShapeList generate_ShapeList() {
    ShapeList sl;

    Circle_p c = make_shared<Circle>("c1", 1);
    Triangle_p t = make_shared<Triangle>("t1",1,3,3);
    EquiTriangle_p e = make_shared<EquiTriangle>("et",2);

    sl.push_back(c);
    sl.push_back(t);
    sl.push_back(e);

    //smart pointers in list surive list copy
    return sl; 
}

int main() {
    ShapeList sl = generate_ShapeList();

    for(ShapeList_citer sli = sl.begin(); sli != sl.end(); sli++) 
        cout << "Shape " << (*sli)->get_name() 
             << " has area = " << (*sli)->area() << endl;
    cout << endl;

    sl.pop_back(); // destroy last added element: et
    sl.push_back(make_shared<Triangle>("t2", 1,2,4));

    for(ShapeList_citer sli = sl.begin();sli != sl.end();sli++) {
        cout << "Shape " << (*sli)->get_name() << " is ";

        if(Triangle_p tp = (*sli)->is_triangle())  {
            cout << (tp->is_valid_triangle() ? "a valid" : "an invalid")
                 << " triangle." << endl;
        } else {
            cout << "not a triangle" << endl;
        }
    }   
    

    return 0;
}