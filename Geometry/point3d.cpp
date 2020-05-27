// OUTSIDE MAIN


struct point3d {
    double x, y, z;

    point3d(): x(0), y(0), z(0) {}
    point3d(double x, double y, double z): x(x), y(y), z(z) {}

    point3d& operator+=(const point3d &t) {
        x += t.x;
        y += t.y;
        z += t.z;
        return *this;
    }
    point3d& operator-=(const point3d &t) {
        x -= t.x;
        y -= t.y;
        z -= t.z;
        return *this;
    }
    point3d& operator*=(double t) {
        x *= t;
        y *= t;
        z *= t;
        return *this;
    }
    point3d& operator/=(double t) {
        x /= t;
        y /= t;
        z /= t;
        return *this;
    }

    point3d operator+(const point3d &t) const { return point3d(*this) += t; }
    point3d operator-(const point3d &t) const { return point3d(*this) -= t; }
    point3d operator*(double t) const { return point3d(*this) *= t; }
    point3d operator/(double t) const { return point3d(*this) /= t; }

};