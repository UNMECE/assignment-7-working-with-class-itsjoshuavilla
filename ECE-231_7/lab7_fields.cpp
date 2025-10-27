
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>

class Electric_Field {
private:
    double* E; // E[0]=Ex, E[1]=Ey, E[2]=Ez

public:
    // Default constructor
    Electric_Field() : E(new double[3]{0.0, 0.0, 0.0}) {}

    // Component constructor
    Electric_Field(double Ex, double Ey, double Ez) : E(new double[3]{Ex, Ey, Ez}) {}

    // Copy constructor (Rule of Three)
    Electric_Field(const Electric_Field& other) : E(new double[3]) {
        E[0] = other.E[0]; E[1] = other.E[1]; E[2] = other.E[2];
    }

    // Assignment operator (Rule of Three)
    Electric_Field& operator=(const Electric_Field& other) {
        if (this != &other) {
            E[0] = other.E[0]; E[1] = other.E[1]; E[2] = other.E[2];
        }
        return *this;
    }

    // Destructor
    ~Electric_Field() { delete[] E; }

    // Getters
    double getX() const { return E[0]; }
    double getY() const { return E[1]; }
    double getZ() const { return E[2]; }

    // Setters
    void setX(double v) { E[0] = v; }
    void setY(double v) { E[1] = v; }
    void setZ(double v) { E[2] = v; }
    void set(double Ex, double Ey, double Ez) { E[0]=Ex; E[1]=Ey; E[2]=Ez; }

    // Magnitude
    double calculateMagnitude() const {
        return std::sqrt(E[0]*E[0] + E[1]*E[1] + E[2]*E[2]);
    }

    // Electric-field-specific: inner product of the vector with itself (E·E)
    double innerProduct() const {
        return E[0]*E[0] + E[1]*E[1] + E[2]*E[2];
    }

    // Utility for printing
    void print(const std::string& label="E") const {
        std::cout << label << " = (" << E[0] << ", " << E[1] << ", " << E[2] << ")\n";
    }
};

class Magnetic_Field {
private:
    double* B; // B[0]=Bx, B[1]=By, B[2]=Bz

public:
    // Default constructor
    Magnetic_Field() : B(new double[3]{0.0, 0.0, 0.0}) {}

    // Component constructor
    Magnetic_Field(double Bx, double By, double Bz) : B(new double[3]{Bx, By, Bz}) {}

    // Copy constructor (Rule of Three)
    Magnetic_Field(const Magnetic_Field& other) : B(new double[3]) {
        B[0] = other.B[0]; B[1] = other.B[1]; B[2] = other.B[2];
    }

    // Assignment operator (Rule of Three)
    Magnetic_Field& operator=(const Magnetic_Field& other) {
        if (this != &other) {
            B[0] = other.B[0]; B[1] = other.B[1]; B[2] = other.B[2];
        }
        return *this;
    }

    // Destructor
    ~Magnetic_Field() { delete[] B; }

    // Getters
    double getX() const { return B[0]; }
    double getY() const { return B[1]; }
    double getZ() const { return B[2]; }

    // Setters
    void setX(double v) { B[0] = v; }
    void setY(double v) { B[1] = v; }
    void setZ(double v) { B[2] = v; }
    void set(double Bx, double By, double Bz) { B[0]=Bx; B[1]=By; B[2]=Bz; }

    // Magnitude
    double calculateMagnitude() const {
        return std::sqrt(B[0]*B[0] + B[1]*B[1] + B[2]*B[2]);
    }

    // Magnetic-field-specific: unit vector
    // Writes components to ux, uy, uz; returns false if zero vector
    bool unitVector(double& ux, double& uy, double& uz) const {
        double mag = calculateMagnitude();
        if (mag == 0.0) { ux = uy = uz = 0.0; return false; }
        ux = B[0] / mag; uy = B[1] / mag; uz = B[2] / mag;
        return true;
    }

    void print(const std::string& label="B") const {
        std::cout << label << " = (" << B[0] << ", " << B[1] << ", " << B[2] << ")\n";
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(4);

    // --- Electric fields ---
    Electric_Field E_default;                       // default ctor
    Electric_Field E_components(1e5, 10.9, 1.7e2);  // 3-component ctor
    Electric_Field E_set;                           // default, then setters
    E_set.setX(3.0); E_set.setY(4.0); E_set.setZ(12.0);

    E_default.print("E_default");
    E_components.print("E_components");
    E_set.print("E_set");

    std::cout << "Magnitude(E_default)   = " << E_default.calculateMagnitude() << "\n";
    std::cout << "Magnitude(E_components)= " << E_components.calculateMagnitude() << "\n";
    std::cout << "Magnitude(E_set)       = " << E_set.calculateMagnitude() << "\n";

    // Electric field specific: inner product (E·E)
    std::cout << "Inner product (E_components · E_components) = "
              << E_components.innerProduct() << "\n\n";

    // --- Magnetic fields ---
    Magnetic_Field B_default;                      // default ctor
    Magnetic_Field B_components(0.3, -1.2, 2.4);  // 3-component ctor
    Magnetic_Field B_set;                          // default, then setters
    B_set.set(5.0, 0.0, 0.0);

    B_default.print("B_default");
    B_components.print("B_components");
    B_set.print("B_set");

    std::cout << "Magnitude(B_default)   = " << B_default.calculateMagnitude() << "\n";
    std::cout << "Magnitude(B_components)= " << B_components.calculateMagnitude() << "\n";
    std::cout << "Magnitude(B_set)       = " << B_set.calculateMagnitude() << "\n";

    // Magnetic field specific: unit vector
    double ux, uy, uz;
    if (B_components.unitVector(ux, uy, uz)) {
        std::cout << "Unit vector of B_components = (" << ux << ", " << uy << ", " << uz << ")\n";
    } else {
        std::cout << "Unit vector of B_components is undefined (zero vector).\n";
    }

    if (B_default.unitVector(ux, uy, uz)) {
        std::cout << "Unit vector of B_default = (" << ux << ", " << uy << ", " << uz << ")\n";
    } else {
        std::cout << "Unit vector of B_default is undefined (zero vector).\n";
    }

    return 0;
}
