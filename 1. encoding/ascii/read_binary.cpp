#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("encoding", std::ios::binary);

    if (file) {
        // File opened successfully in binary mode
        // You can read and process the file here

        // For example, read the contents of the file byte by byte
        char byte;
        while (file.read(&byte, sizeof(byte))) {
            // Process each byte as needed
            // You can access the byte value using 'byte' variable
            std::string binaryString = std::bitset<8>(byte).to_string();
            std::cout << binaryString;
        }

        // Close the file after reading
        file.close();
    } else {
        // Failed to open the file
        std::cout << "Failed to open the binary file." << std::endl;
    }

    return 0;
}