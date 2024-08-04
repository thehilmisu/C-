#include <iostream>
#include <vector>
#include <sstream>
#include <termios.h>
#include <unistd.h>

// Function to clear the entire screen
void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

// Function to move the cursor to the beginning of the line
void moveCursorToLineStart(int line) {
    std::cout << "\033[" << line << ";1H";
}

// Function to clear a specific line
void clearLine(int line) {
    moveCursorToLineStart(line);
    std::cout << "\033[K"; // Clear the line from the cursor to the end
}

// Function to hide the cursor
void hideCursor() {
    std::cout << "\033[?25l";
}

// Function to show the cursor
void showCursor() {
    std::cout << "\033[?25h";
}

// Function to print lines with highlighting the selected line
void printLines(const std::vector<std::string>& lines, int startIndex, int selectedIndex) {
    for (int i = 0; i < 6; ++i) {
        if (startIndex + i >= lines.size()) {
            clearLine(i + 1);
            continue;
        }
        clearLine(i + 1);
        moveCursorToLineStart(i + 1);
        if (startIndex + i == selectedIndex) {
            std::cout << "> " << lines[startIndex + i] << std::endl;
        } else {
            std::cout << "  " << lines[startIndex + i] << std::endl;
        }
    }
    std::cout.flush(); // Ensure output is displayed
}

// Function to print the detailed message
void printDetail(const std::string& detail, int startLine) {
    std::istringstream stream(detail);
    std::string line;
    int lineNum = startLine;
    
    while (std::getline(stream, line)) {
        moveCursorToLineStart(lineNum);
        clearLine(lineNum);
        std::cout << line << std::endl;
        ++lineNum;
    }
    std::cout.flush(); // Ensure output is displayed
}

// Function to get a single key press
char getKeyPress() {
    struct termios oldt, newt;
    char ch;

    // Get terminal attributes
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // Disable canonical mode and echo
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Read a character
    ch = std::cin.get();

    // Restore terminal attributes
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

int main() {
    std::vector<std::string> lines = {
        "Line 1: Hello World",
        "Line 2: Welcome to C++",
        "Line 3: This is a test",
        "Line 4: Navigate with arrow keys",
        "Line 5: Press Enter to select",
        "Line 6: Press q to exit",
        "Line 7: Additional Line 1",
        "Line 8: Additional Line 2",
        "Line 9: Additional Line 3",
        "Line 10: Additional Line 4",
        "Line 11: Additional Line 5",
        "Line 12: Additional Line 6"
    };

    std::vector<std::string> details = {
        "Detailed message for Line 1: Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec vel nunc euismod, pharetra justo non, pretium massa.",
        "Detailed message for Line 2: Sed sit amet eros vitae sem vehicula interdum. Cras euismod risus eu eros aliquam, nec fermentum augue ullamcorper.",
        "Detailed message for Line 3: Quisque in libero eu felis volutpat tempus. Nam cursus neque sit amet magna vestibulum, nec consectetur libero pulvinar.",
        "Detailed message for Line 4: Integer euismod nulla ut augue ultricies, a interdum felis sagittis. Vivamus vel magna et dui condimentum tincidunt.",
        "Detailed message for Line 5: Donec tincidunt nulla ac augue bibendum, at pharetra purus posuere. Pellentesque habitant morbi tristique senectus et netus.",
        "Detailed message for Line 6: Nulla facilisi. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Vivamus at volutpat lacus.",
        "Detailed message for Line 7: Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec vel nunc euismod, pharetra justo non, pretium massa.",
        "Detailed message for Line 8: Sed sit amet eros vitae sem vehicula interdum. Cras euismod risus eu eros aliquam, nec fermentum augue ullamcorper.",
        "Detailed message for Line 9: Quisque in libero eu felis volutpat tempus. Nam cursus neque sit amet magna vestibulum, nec consectetur libero pulvinar.",
        "Detailed message for Line 10: Integer euismod nulla ut augue ultricies, a interdum felis sagittis. Vivamus vel magna et dui condimentum tincidunt.",
        "Detailed message for Line 11: Donec tincidunt nulla ac augue bibendum, at pharetra purus posuere. Pellentesque habitant morbi tristique senectus et netus.",
        "Detailed message for Line 12: Nulla facilisi. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Vivamus at volutpat lacus."
    };

    int selectedIndex = 0;
    int startIndex = 0;
    bool running = true;

    clearScreen();
    hideCursor();
    printLines(lines, startIndex, selectedIndex);

    while (running) {
        char ch = getKeyPress();
        switch (ch) {
            case '\033': // Escape sequence
                if (std::cin.get() == '[') { // Ignore the [
                    switch (std::cin.get()) {
                        case 'A': // Up arrow
                            if (selectedIndex > 0) {
                                --selectedIndex;
                                if (selectedIndex < startIndex) {
                                    startIndex = selectedIndex;
                                }
                            }
                            break;
                        case 'B': // Down arrow
                            if (selectedIndex < lines.size() - 1) {
                                ++selectedIndex;
                                if (selectedIndex >= startIndex + 6) {
                                    startIndex = selectedIndex - 5;
                                }
                            }
                            break;
                    }
                }
                break;
            case '\n': // Enter key
                clearScreen();
                printLines(lines, startIndex, selectedIndex);
                printDetail(details[selectedIndex], 8); // Print detail below the lines
                break;
            case 'q': // 'q' key to quit
                clearScreen();
                running = false;
                break;
        }
        printLines(lines, startIndex, selectedIndex);
    }

    showCursor();
    return 0;
}
