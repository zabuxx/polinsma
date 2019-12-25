#include <memory>
#include <array>
#include <string>
#include <list>

using namespace std;

// Forward declaration of defined classes and their pointers
class Shape;
class Circle;
class Triangle;
class EquiTriangle;

typedef shared_ptr<Shape>    Shape_p;
typedef shared_ptr<Circle>   Circle_p;
typedef shared_ptr<Triangle> Triangle_p;
typedef shared_ptr<EquiTriangle> EquiTriangle_p;

typedef weak_ptr<Shape>    Shape_wp;
typedef weak_ptr<Circle>   Circle_wp;
typedef weak_ptr<Triangle> Triangle_wp;
typedef weak_ptr<EquiTriangle> EquiTriangle_wp;

//list type to contain all types of classes through Shape_p
typedef list<Shape_p> ShapeList;
typedef list<Shape_p>::iterator ShapeList_iter;
typedef list<Shape_p>::const_iterator ShapeList_citer;


/*! \brief Base class for all other Shape classes
 *
 * As an abstract class, Shape will act as base class for all other shapes. As
 * such any derived class can be addressed using a Shape pointer (Shape_p).
 *
 * The is_* functions can be used to promote the Shape_p to the relevant type.
 * See main.cpp.
 */

class Shape: public enable_shared_from_this<Shape>  {
    protected:
        string name;
    public:
        //Shape needs at least a name
        Shape(const string& n) : 
            name(n) { };

        string get_name() const { return name; }

        virtual double area() const = 0;

        //is_XXX() function allows opbtaining shared_ptr to a derived class. At
        //this point just return empty shared_ptr to allow testing class type
        //(through coversion to bool), to be overloaded in derived class.
        virtual Circle_p       is_circle()       { return Circle_p(); }
        virtual Triangle_p     is_triangle()     { return Triangle_p(); }
        virtual EquiTriangle_p is_equitriangle() { return EquiTriangle_p(); }
};

class Circle : public Shape{
    private:
        double radius;
    public:
        //Initialize circle by specifying radius
        Circle(const string& n, double r) : 
            Shape(n), radius(r) { }

        double area() const { return radius * radius * 3.14159; }

        virtual Circle_p is_circle() { 
            return dynamic_pointer_cast<Circle>(shared_from_this()); }
};

class Triangle : public Shape {
    private:
        array<double, 3> length;
    public:
        //Initialize triangle by specifying length of each side
        Triangle(const string&, double, double, double);

        bool is_valid_triangle() const;

        double area() const;

        virtual Triangle_p is_triangle() { 
            return dynamic_pointer_cast<Triangle>(shared_from_this()); }
};

class EquiTriangle : public Triangle {
    public:
        //Initliaize the equilateral triangle by specifying length of a side
        EquiTriangle(const string& n, double l) : 
            Triangle(n,l,l,l) { }

        virtual EquiTriangle_p is_equitriangle() { 
            return dynamic_pointer_cast<EquiTriangle>(shared_from_this()); }
};
