//
// Created by mcavazotti on 6/20/25.
//

export module vector;

export class Vector2
{
    public:
    // start-constructors
    Vector2(const double x, const double y): x(x), y(y) {};
    Vector2(const Vector2 &v);
    // end-constructors


    double x, y;
};