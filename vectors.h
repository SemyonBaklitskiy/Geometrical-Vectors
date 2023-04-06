#pragma once
#include <iostream>

class points {
    friend std::istream& operator>>(std::istream&, points&);

protected:
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

public:
    points(const double x, const double y, const double z): x(x), y(y), z(z) {}

    points() = default;
    ~points() = default;

    points(const points& point) {
        x = point.x;
        y = point.y;
        z = point.z;
    }

    points& operator=(const points& point);
    bool operator==(const points& point) const;
    bool operator!=(const points& point) const;
    double get_x() const;
    double get_y() const;
    double get_z() const;
};

class vectors: public points {
public:
    vectors(const double x, const double y, const double z): points(x, y, z) {}
    vectors(const points& point): points(point) {}
    vectors() = default;

    vectors(const vectors& vec): points(vec) {}

    ~vectors() = default;

    vectors& operator+=(const vectors& vec);
    vectors& operator-=(const vectors& vec);
    vectors& operator*=(const double val);
    vectors& operator/=(const double val);
    vectors& operator*=(const vectors& vec);
    vectors& operator++();
    vectors operator++(int);
    vectors& operator--();
    vectors operator--(int);
    double operator,(const vectors& vec) const;

    double length() const;
    void wrap();

};

std::istream& operator>>(std::istream& in, points& point);
std::ostream& operator<<(std::ostream& out, const points& point);

vectors operator*(const vectors vec1, const vectors vec2);
vectors operator+(const vectors& vec1, const vectors& vec2);
vectors operator-(const vectors& vec1, const vectors& vec2);
vectors operator*(const double val, const vectors vec);
vectors operator*(const vectors vec, const double val);
vectors operator/(const vectors vec, const double val);
