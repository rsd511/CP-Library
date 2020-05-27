// OUTSIDE MAIN


struct point2d {

    double x, y;

    point2d(): x(0), y(0) {}
    point2d(double x, double y): x(x), y(y) {}

    point2d& operator+=(const point2d &t) {
        x += t.x;
        y += t.y;
        return *this;
    }
    point2d& operator-=(const point2d &t) {
        x -= t.x;
        y -= t.y;
        return *this;
    }
    point2d& operator*=(double t) {
        x *= t;
        y *= t;
        return *this;
    }
    point2d& operator/=(double t) {
        x /= t;
        y /= t;
        return *this;
    }

    point2d operator+(const point2d &t) const { return point2d(*this) += t; }
    point2d operator-(const point2d &t) const { return point2d(*this) -= t; }
    point2d operator*(double t) const { return point2d(*this) *= t; }
    point2d operator/(double t) const { return point2d(*this) /= t; }

};