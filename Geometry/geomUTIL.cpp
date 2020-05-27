// OUTSIDE MAIN


// 2D-point
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

// 3D-point
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

// Dot-Product
double dot(point2d a, point2d b) {
    return a.x * b.x + a.y * b.y;
}
double dot(point3d a, point3d b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

// (2D) - Length, Projection & Angle
double norm(point2d a) {
    return dot(a, a);
}
double abs(point2d a) {
    return sqrt(norm(a));
}
double proj(point2d a, point2d b) {
    return dot(a, b) / abs(b);
}
double angle(point2d a, point2d b) {
    return acos(dot(a, b) / abs(a) / abs(b));
}

// Cross & Triple Product
point3d cross(point3d a, point3d b) {
    return point3d(a.y * b.z - a.z * b.y,
                   a.z * b.x - a.x * b.z,
                   a.x * b.y - a.y * b.x);
}
double triple(point3d a, point3d b, point3d c) {
    return dot(a, cross(b, c));
}
double cross(point2d a, point2d b) {
    return a.x * b.y - a.y * b.x;
}

// (2D) - Orientation
// p - reference, q - 1st point, r - 2nd point
// 0 - collinear, 1 - clockwise, -1 - anti-clockwise
int orientation(point2d p, point2d q, point2d r) 
{
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val <= 1e-6 && val >= -1e-6) return 0;
    return (val > 1e-6)? 1: -1; 
}
ll orientation(pair <ll,ll> p, pair <ll,ll> q, pair <ll,ll> r) 
{
    ll val = (q.ss - p.ss) * (r.ff - q.ff) - (q.ff - p.ff) * (r.ss - q.ss);
    if (val == 0) return 0;
    return (val > 0)? 1: -1; 
}