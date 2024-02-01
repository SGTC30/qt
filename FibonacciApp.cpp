// FibonacciApp.cpp
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>

// A function that returns the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// A class that represents the main window of the application
class FibonacciApp : public QWidget {
public:
    FibonacciApp(QWidget *parent = nullptr);
private slots:
    // A slot that handles the button click event
    void onButtonClick();
private:
    // A pointer to the line edit widget
    QLineEdit *lineEdit;
    // A pointer to the label widget
    QLabel *label;
};

// The constructor of the FibonacciApp class
FibonacciApp::FibonacciApp(QWidget *parent) : QWidget(parent) {
    // Create a line edit widget
    lineEdit = new QLineEdit();
    // Set the placeholder text
    lineEdit->setPlaceholderText("Enter a positive integer");
    // Create a push button widget
    QPushButton *button = new QPushButton("Calculate");
    // Connect the button click signal to the slot
    connect(button, &QPushButton::clicked, this, &FibonacciApp::onButtonClick);
    // Create a label widget
    label = new QLabel();
    // Set the alignment of the label
    label->setAlignment(Qt::AlignCenter);
    // Create a vertical layout
    QVBoxLayout *layout = new QVBoxLayout();
    // Add the widgets to the layout
    layout->addWidget(lineEdit);
    layout->addWidget(button);
    layout->addWidget(label);
    // Set the layout of the window
    setLayout(layout);
    // Set the window title
    setWindowTitle("Fibonacci App");
}

// The slot that handles the button click event
void FibonacciApp::onButtonClick() {
    // Get the text from the line edit widget
    QString text = lineEdit->text();
    // Try to convert the text to an integer
    bool ok;
    int n = text.toInt(&ok);
    // If the conversion was successful and the number is positive
    if (ok && n > 0) {
        // Calculate the nth Fibonacci number
        int f = fibonacci(n);
        // Display the result in the label widget
        label->setText(QString("Fibonacci(%1) = %2").arg(n).arg(f));
    }
    // Otherwise
    else {
        // Show an error message
        QMessageBox::critical(this, "Error", "Invalid input. Please enter a positive integer.");
    }
}

// The main function of the application
int main(int argc, char *argv[]) {
    // Create a QApplication object
    QApplication app(argc, argv);
    // Create a FibonacciApp object
    FibonacciApp window;
    // Show the window
    window.show();
    // Execute the application
    return app.exec();
}
