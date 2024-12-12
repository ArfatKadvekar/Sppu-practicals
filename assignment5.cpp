#include <iostream>
#include <string>
#include <stdexcept> // For std::runtime_error

using namespace std;

class Publication {
public:
    string title;
    float price;

    // Default constructor
    Publication() : title(""), price(0.0f) {}

    void getPublication() {
        cout << "Enter title: ";
        cin.ignore(); // Clear input buffer
        getline(cin, title); // Allow spaces in title
        cout << "Enter price: ";
        cin >> price;

        // Check for negative price
        if (price < 0) {
            throw runtime_error("Price cannot be negative.");
        }
    }

    void reset() {
        title = "";
        price = 0.0f;
    }

    void display() const {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }

    // Destructor
    virtual ~Publication() {
        cout << "Publication destructor called." << endl;
    }
};

class Book : public Publication {
public:
    int pageCount;

    // Default constructor
    Book() : pageCount(0) {}

    void getBook() {
        this->getPublication();
        cout << "Enter page count: ";
        cin >> pageCount;

        // Check for negative page count
        if (pageCount < 0) {
            throw runtime_error("Page count cannot be negative.");
        }
    }

    void display() const {
        Publication::display(); // Call base class display
        cout << "Page Count: " << pageCount << endl;
    }

    // Destructor
    ~Book() {
        cout << "Book destructor called." << endl;
    }
};

class Tape : public Publication {
public:
    float playingTime;

    // Default constructor
    Tape() : playingTime(0.0f) {}

    void getTape() {
        this->getPublication();
        cout << "Enter playing time in minutes: ";
        cin >> playingTime;

        // Check for negative playing time
        if (playingTime < 0) {
            throw runtime_error("Playing time cannot be negative.");
        }
    }

    void display() const {
        Publication::display(); // Call base class display
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }

    // Destructor
    ~Tape() {
        cout << "Tape destructor called." << endl;
    }
};

int main() {
    Book b;
    Tape t;

    try {
        cout << "Enter details for the book:" << endl;
        b.getBook();
        
        cout << "\nEnter details for the tape:" << endl;
        t.getTape();
    } catch (const runtime_error &e) {
        cout << "\nException caught: " << e.what() << endl;
        cout << "Resetting all data members to zero values." << endl;
        
        b.reset();
        t.reset();
    }

    // Display information
    cout << "\nBook Details:" << endl;
    b.display();
    
    cout << "\nTape Details:" << endl;
    t.display();

    return 0;
}
