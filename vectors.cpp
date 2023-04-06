#include <iostream>
#include <cmath>
#include "vectors.h"

static double sqr(const double val) {
    return val * val;
}

points& points::operator=(const points& point) {
    if (this == &point)
        return *this;

    x = point.x;
    y = point.y;
    z = point.z;

    return *this;
}

vectors& vectors::operator++() {
    ++x;
    ++y;
    ++z;

    return *this;
}

vectors vectors::operator++(int) {
    vectors copy = *this;

    ++x;
    ++y;
    ++z;

    return copy;
}

vectors& vectors::operator--() {
    --x;
    --y;
    --z;

    return *this;
}

vectors vectors::operator--(int) {
    vectors copy = *this;

    --x;
    --y;
    --z;

    return copy;
}

bool points::operator==(const points& point) const {
    return ((x == point.x) && (y == point.y) && (z == point.z));
}

bool points::operator!=(const points& point) const {
    return !((x == point.x) && (y == point.y) && (z == point.z));
}

double points::get_x() const {
    return x;
}

double points::get_y() const {
    return y;
}

double points::get_z() const {
    return z;
}

std::istream& operator>>(std::istream& in, points& point) {
    std::cout << "Enter x y z: ";
    in >> point.x >> point.y >> point.z;
    return in;
}

std::ostream& operator<<(std::ostream& out, const points& point) {
    out << "(" << point.get_x() << ", " << point.get_y() << ", " << point.get_z() << ")";
    return out;
}

double vectors::operator,(const vectors& vec) const {
    return x * vec.x + y * vec.y + z * vec.z;
}

vectors& vectors::operator*=(const vectors& vec) {
    x = y * vec.z - z * vec.y;
    y = z * vec.x - x * vec.z;
    z = x * vec.y - y * vec.x;

    return *this;
}

vectors& vectors::operator+=(const vectors& vec) {
    x += vec.x;
    y += vec.y;
    z += vec.z;

    return *this;
}

vectors& vectors::operator-=(const vectors& vec) {
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;

    return *this;
}

vectors& vectors::operator*=(const double val) {
    x *= val;
    y *= val;
    z *= val;

    return *this;
}

vectors& vectors::operator/=(const double val) {
    x /= val;
    y /= val;
    z /= val;

    return *this;
}

vectors operator*(const vectors vec1, const vectors vec2) {
    vectors vec = vec1;
    vec *= vec2;

    return vec;
}

vectors operator+(const vectors& vec1, const vectors& vec2) {
    vectors vec = vec1;
    vec += vec2;

    return vec;
}

vectors operator-(const vectors& vec1, const vectors& vec2) {
    vectors vec = vec1;
    vec -= vec2;

    return vec;
}

vectors operator*(const double val, const vectors vec) {
    vectors result = vec;
    result *= val;

    return result;
}

vectors operator*(const vectors vec, const double val) {
    return val * vec;
}

vectors operator/(const vectors vec, const double val) {
    vectors result = vec;
    result /= val;

    return result;
}

double vectors::length() const {
    return sqrt(sqr(x) + sqr(y) + sqr(z));
}

void vectors::wrap() {
    x *= -1;
    y *= -1;
    z *= -1;
}



