/// @brief 3次元ベクトル
/// @tparam T 要素x,y,zの型
template <typename T>
class Vector3
{
    public:
    // Member variables
    T x;
    T y;
    T z;

    // Constructors
    Vector3(T x = 0, T y = 0, T z = 0) : x(x), y(y), z(z) {}

    // Static member functions
    static Vector3<T> zero() {
        return Vector3<T>();
    }
    static double distance(const Vector3<T>& a, const Vector3<T>& b) {
        return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
    }

    // Member functions
    double length() const {
        return std::sqrt(x * x + y * y + z * z);
    }
    double squaredLength() const {
        return x * x + y * y + z * z;
    }
    double distance(const Vector3<T>& other) const {
        return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y) + (z - other.z) * (z - other.z));
    }
    void normalize() {
        double len = length();
        if (len <= 0) return;
        *this /= len;
    }

    // Operators
    Vector3<T> operator+(const Vector3<T>& other) const {
        return Vector3<T>(x + other.x, y + other.y, z + other.z);
    }

    Vector3<T>& operator+=(const Vector3<T>& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    Vector3<T> operator-(const Vector3<T>& other) const {
        return Vector3<T>(x - other.x, y - other.y, z - other.z);
    }

    Vector3<T>& operator-=(const Vector3<T>& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    Vector3<T> operator*(long scalar) const {
        return Vector3<T>(x * scalar, y * scalar, z * scalar);
    }
    Vector3<T> operator*(double scalar) const {
        return Vector3<T>(x * scalar, y * scalar, z * scalar);
    }

    Vector3<T>& operator*=(long scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }
    Vector3<T>& operator*=(double scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    Vector3<T> operator/(long scalar) const {
        if (scalar == 0) throw std::invalid_argument("Division by zero");

        return Vector3<T>(x / scalar, y / scalar, z / scalar);
    }
    Vector3<T> operator/(double scalar) const {
        if (scalar == 0) throw std::invalid_argument("Division by zero");

        return Vector3<T>(x / scalar, y / scalar, z / scalar);
    }

    Vector3<T>& operator/=(long scalar) {
        if (scalar == 0) throw std::invalid_argument("Division by zero");

        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }
    Vector3<T>& operator/=(double scalar) {
        if (scalar == 0) throw std::invalid_argument("Division by zero");

        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }

    /// @brief 内積
    T operator^(const Vector3<T>& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    bool operator==(const Vector3<T>& other) const {
        return (x == other.x && y == other.y && z == other.z);
    }

    bool operator!=(const Vector3<T>& other) const {
        return !(*this == other);
    }
};
