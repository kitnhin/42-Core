#include <iostream>
#include <stdexcept>
#include <string>

int main() {
    try {
        std::string str = "123avd"; // A very large number
        double value = std::stod(str); // This will throw std::out_of_range
        std::cout << "The value is: " << value << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: The number is out of the representable range for a double." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: Invalid argument for conversion." << std::endl;
    }

    return 0;
}
