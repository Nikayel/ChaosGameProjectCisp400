// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
    // Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Timber Game!!", Style::Default);

    vector<Vector2f> vertices;
    vector<Vector2f> points;

	while (window.isOpen())
	{
        /*
		****************************************
		Handle the players input
		****************************************
		*/
        Event event;
		while (window.pollEvent(event))
		{
            if (event.type == Event::Closed)
            {
				// Quit the game when the window is closed
				window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "the left button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;

                    if(vertices.size() < 3)
                    {
                        vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
                    }
                    else if(points.size() == 0)
                    {
                        ///fourth click
                        ///push back to points vector
                        points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
                    }
                }
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
        /*
		****************************************
		Update
		****************************************
		*/

        if(points.size() > 0)
        {
            ///generate more point(s)
            ///select random vertex
            ///calculate midpoint between random vertex and the last point in the vector
            ///push back the newly generated coord.
             int randomVertexIndex = rand() % vertices.size();
            Vector2f randomVertex = vertices[randomVertexIndex];

            // Calculate midpoint between random vertex and the last point
            Vector2f midpoint = (randomVertex + points.back()) / 2.0f;

            // Push back the newly generated coordinate
            points.push_back(midpoint);

            // Draw the new point
            RectangleShape rect(Vector2f(5, 5));
            rect.setPosition(midpoint);
            rect.setFillColor(Color::Red);
            window.draw(rect);
        }

        /*
		****************************************
		Draw
		****************************************
		*/
        window.clear();
        for(size_t i = 0; i < vertices.size(); i++)
        {
            RectangleShape rect(Vector2f(10,10));
            rect.setPosition(Vector2f(vertices[i].x, vertices[i].y));
            rect.setFillColor(Color::Blue);
            window.draw(rect);
        }
         for (size_t i = 0; i < points.size(); i++)
        {
            // Draw the generated points
            RectangleShape rect(Vector2f(5, 5));
            rect.setPosition(Vector2f(points[i].x, points[i].y));
            rect.setFillColor(Color::red);
            window.draw(rect);
        }

        window.display();
    }
}
