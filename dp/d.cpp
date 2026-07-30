#include "bits/stdc++.h"
#include <vector>

using namespace std;
/// @brief 2次元ベクトル
/// @tparam T 要素x,yの型
template <typename T>
class Vector2
{
    public:
    // Member variables
    T x;
    T y;

    // Constructors
    Vector2(T x, T y) : x(x), y(y) {}

    // Static member functions
    static Vector2<T> zero() {
        return Vector2<T>();
    }
    static double distance(const Vector2<T>& a, const Vector2<T>& b) {
        return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }

    // Member functions
    double length() const {
        return std::sqrt(x * x + y * y);
    }
    double squaredLength() const {
        return x * x + y * y;
    }
    double distance(const Vector2<T>& other) const {
        return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }
    void normalize() {
        double len = length();
        if (len <= 0) return;
        *this /= len;
    }

    // Operators
    Vector2<T> operator+(const Vector2<T>& other) const {
        return Vector2<T>(x + other.x, y + other.y);
    }

    Vector2<T>& operator+=(const Vector2<T>& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2<T> operator-(const Vector2<T>& other) const {
        return Vector2<T>(x - other.x, y - other.y);
    }

    Vector2<T>& operator-=(const Vector2<T>& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector2<T> operator*(long scalar) const {
        return Vector2<T>(x * scalar, y * scalar);
    }
    Vector2<T> operator*(double scalar) const {
        return Vector2<T>(x * scalar, y * scalar);
    }

    Vector2<T>& operator*=(long scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }
    Vector2<T>& operator*=(double scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vector2<T> operator/(long scalar) const {
        if (scalar == 0) throw std::invalid_argument("Division by zero");

        return Vector2<T>(x / scalar, y / scalar);
    }
    Vector2<T> operator/(double scalar) const {
        if (scalar == 0) throw std::invalid_argument("Division by zero");

        return Vector2<T>(x / scalar, y / scalar);
    }

    Vector2<T>& operator/=(long scalar) {
        if (scalar == 0) throw std::invalid_argument("Division by zero");

        x /= scalar;
        y /= scalar;
        return *this;
    }
    Vector2<T>& operator/= (double scalar) {
        if (scalar == 0) throw std::invalid_argument("Division by zero");

        x /= scalar;
        y /= scalar;
        return *this;
    }

    /// @brief 内積
    T operator^(const Vector2<T>& other) const {
        return x * other.x + y * other.y;
    }

    bool operator==(const Vector2<T>& other) const {
        return (x == other.x && y == other.y);
    }

    bool operator!=(const Vector2<T>& other) const {
        return !(*this == other);
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<Vector2<int>> items(N);
    for (int i = 0; i < N; i++) {
        cin >> items[i].x >> items[i].y;
    }

    vector<vector<int>> dp(N + 1, vector<int>(M + 1));

    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < M + 1; j++) {
            if (i == 0) {
                dp[i][j] = 0;
            } else {
                dp[i][j] =
            }
        }
    }
}
