#ifndef ENGINEHEADERS_H
#define ENGINEHEADERS_H


#include <iostream>
#include <experimental/filesystem>
#include <unistd.h>

#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

// std namespace
using std::vector;
using std::map;
using std::multimap;
using std::string;
using std::cout;
using std::endl;
using std::pair;
using std::make_pair;
using std::stoi;
using std::stof;
using std::abs;
using std::runtime_error;
using std::size;
using std::experimental::filesystem::path;

// SFML namespace
using sf::Transformable;
using sf::Transform;
using sf::Drawable;
using sf::Texture;
using sf::Image;
using sf::Sprite;
using sf::Vertex;
using sf::TriangleStrip;
using sf::RenderWindow;
using sf::RenderTarget;
using sf::RenderStates;
using sf::VideoMode;
using sf::View;
using sf::Color;
using sf::Event;
using sf::Keyboard;
using sf::Uint8;
using sf::IntRect;
using sf::FloatRect;
using sf::Vector2f;
using sf::Vector2i;
using sf::Vector2u;


#endif // ENGINEHEADERS_H
