// Fait par Mathias Lavoie : LAVM19040400
#include <iostream>
#include <string>

#include "Point.h"
#include "Coord.h"

//Returns a string of Point in this format : (x, y)
string p_to_s(const Point&);

int main()
{
    Point p1(1, 4);
    Point p2(3, 2);
    Point p3(3, 1);
    Point p4(5, 5);

    Coord<Point, 2> c1({p1, p2});
    Coord<Point, 2> c2({p3, p4});
    Coord<Point, 3> c3({p2, p3, p4});

    c1 = c2;

    cout << "===== A) Addition =====" << endl;
    cout << p_to_s(c1.get_values()[0]) << " & " << p_to_s(c1.get_values()[1]) << "   +   ";
    cout << p_to_s(c2.get_values()[0]) << " & " << p_to_s(c2.get_values()[1]) << "   =   ";
    Coord<Point, 2> ct = c1 + c2;
    cout << p_to_s(ct.get_values()[0]) << " & " << p_to_s(ct.get_values()[1]);

    cout << endl << endl;

    cout << "===== B) Produit scalaire =====" << endl;
    cout << p_to_s(c1.get_values()[0]) << " & " << p_to_s(c1.get_values()[1]) << "   *   ";
    cout << p_to_s(c2.get_values()[0]) << " & " << p_to_s(c2.get_values()[1]) << "   =   ";
    Point pt = c1 * c2;
    cout << p_to_s(pt);

    cout << endl << endl;

    cout << "===== C) Concatenation =====" << endl;
    cout << p_to_s(c1.get_values()[0]) << " & " << p_to_s(c1.get_values()[1]) << "   avec   ";
    cout << p_to_s(c3.get_values()[0]) << ", " << p_to_s(c3.get_values()[1]) << " & " << p_to_s(c3.get_values()[2]) << "   =   ";
    Coord<Point, 5> cc = concat(c1, c3);
    for (const Point& p : cc.get_values())
    {
        cout << p_to_s(p) << ", ";
    }

    cout << endl << endl;
}

string p_to_s(const Point& p) {
    return "(" + to_string(p.get_x()) + ", " + to_string(p.get_y()) + ")";
}