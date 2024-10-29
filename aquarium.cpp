#include <iostream>

int main()
{
    // variables - color--> 2D, 7 for max number of inputs
    int fish_count;
    char color[7][15];

    // start of svg
    std::cout << "<svg width=\"500\" height=\"400\" xmlns=\"http://www.w3.org/2000/svg\">\n";

    // aquarium
    std::cout << "<rect width=\"500\" height=\"400\" fill=\"#608BC1\" />\n";

    // user input for fish count
    std::cerr << "enter number of fish (maximum 7 fish): "; // using cerr because program crashes when cout used
    // also cerr does not mix everything (errors and outputs)
    std::cin >> fish_count;

    // error message for invalid fish count
    if (fish_count < 1 || fish_count > 7)
    {
        std::cerr << "invalid fish count...exiting\n";
        return 1;
    }
    // user input for fish color
    for (int i = 0; i < fish_count; i++)
    {
        std::cerr << "enter color for fish: ";
        std::cin >> color[i];
    }
    // fish
    for (int i = 0; i < fish_count; ++i)
    {
        int x = 50 + i * 60;
        int y = 150;
        // body of the fish
        std::cout << "<ellipse cx=\"" << x << "\" cy=\"" << y << "\" rx=\"20\" ry=\"10\" fill=\"" << color[i] << "\" />\n";

        // tail of the fish
        std::cout << "<polygon points=\"" << x + 20 << "," << y
                  << " " << x + 30 << "," << y - 10
                  << " " << x + 30 << "," << y + 10
                  << "\" fill=\"" << color[i] << "\" />\n";
    }

    // dark green seaweed
    for (int i = 0; i < 10; ++i)
    {
        int x = 30 + i * 50;
        int y = 250;
        std::cout << "<rect x=\"" << x << "\" y=\"" << y << "\" width=\"15\" height=\"300\" fill=\"#31511E\" />\n";
    }

    // light green seaweed
    for (int i = 0; i < 15; ++i)
    {
        int x = 10 + i * 50;
        int y = 300;
        std::cout << "<rect x=\"" << x << "\" y=\"" << y << "\" width=\"15\" height=\"150\" fill=\"#859F3D\" />\n";
    }

    // end of svg
    std::cout << "</svg>\n";

    return 0;
}