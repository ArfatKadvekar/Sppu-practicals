#include <iostream>
using namespace std;

class Complex {
    float real;
    float img;

public: 
    // Default constructor
    Complex() : real(0.0), img(0.0) {}

    // Parameterized constructor
    Complex(float r, float i) : real(r), img(i) {}

    // Overloading the '+' operator
    Complex operator+(const Complex &c2) {
        Complex temp;
        temp.real = real + c2.real;
        temp.img = img + c2.img; // Corrected addition of imaginary parts
        return temp;
    }

    // Overloading the '*' operator
    Complex operator*(const Complex &c2) {
        Complex temp;
        temp.real = (real * c2.real) - (img * c2.img);
        temp.img = (real * c2.img) + (img * c2.real);
        return temp;
    }

    // Friend function to overload '<<' for output
    friend ostream &operator<<(ostream &out, const Complex &c) {
        out << c.real << "+" << c.img << "i";
        return out; // Return the stream for chaining
    }

    // Friend function to overload '>>' for input
    friend istream &operator>>(istream &in, Complex &c) {
        cout << "Enter the real part: ";
        in >> c.real;
        cout << "Enter the imaginary part: ";
        in >> c.img;
        return in; // Return the stream for chaining
    }
};

int main() {
    Complex c1, c2, c3, c4;

    // Input two complex numbers
    cout << "Enter the first complex number:" << endl;
    cin >> c1;
    cout << "Enter the second complex number:" << endl;
    cin >> c2;

    // Perform addition
    c3 = c1 + c2;

    // Perform multiplication
    c4 = c1 * c2;

    // Output results
    cout << "Sum: " << c3 << endl;
    cout << "Product: " << c4 << endl;

    return 0;
}
