#include <game.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <snake.hpp>
#include <food.hpp>
#include <iostream>
#include "writefile.cpp"
using namespace std;

string nameUser()//save name and score and write them in file
{
  string name;
  cout << "pls enter your name >>> ";
  cin >> name;
  return name;
}

void Game::start()
{
  string name;
  name = nameUser();

  sf::RenderWindow window(sf::VideoMode(800, 800), "Snake game", sf::Style::Close);//creat base window
  
  sf::RectangleShape back_sprite(sf::Vector2f(800, 800));
  sf::Texture background_texture;
  background_texture.loadFromFile("../soil.jpg");//background photo
  back_sprite.setTexture(&background_texture);

  sf::CircleShape spr_food(20.0);//food(apple)shape
  spr_food.setFillColor(sf::Color::Red);//apple color

  food.new_food();//creat new food
  spr_food.setPosition(food.get_foodlocx() * 40, food.get_foodlocy() * 40);//because random food worked with 20*20 but vector2f worked with 800*800 so we should ultiply by 40

  sf::CircleShape head_shape(20.0);//base location for snake head
  head_shape.setFillColor(sf::Color::Green);//head snake color
  head_shape.setPosition(snake.get_location_x(0) * 40, snake.get_location_y(0) * 40);//because random food worked with 20*20 but vector2f worked with 800*800 so we should ultiply by 40

  vector<sf::CircleShape> body_shape;//for body of snake
  sf::CircleShape b1(20.0);//first part of body(the next part of head)
  b1.setFillColor(sf::Color::Black);//body color
  b1.setPosition(snake.get_location_x(1) * 40, snake.get_location_y(1) * 40);//because random food worked with 20*20 but vector2f worked with 800*800 so we should ultiply by 40
  body_shape.push_back(b1);//push back vector for new part of body

  while (window.isOpen())
  {
    sf::Event event;//get key
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)//for close icon in upper
      {
        writefile(name, f_count*10);
        window.close();
      }

      if (event.key.code == sf::Keyboard::Key::A)//West
      {
        for (size_t i = 1; i < snake.get_lenght(); i++)//for body
        {
          snake.set_x(i);//for shift body
          snake.set_y(i);//for shift body
          body_shape[i - 1].setPosition(snake.get_location_x(i) * 40, snake.get_location_y(i) * 40);
        }

        snake.set_location_x(0, -1);//for haed
        head_shape.setPosition(snake.get_location_x(0) * 40, snake.get_location_y(0) * 40);//for head
      }
      
      if (event.key.code == sf::Keyboard::Key::D)//East 
      {
        for (size_t i = 1; i < snake.get_lenght(); i++)//for body
        {
          snake.set_x(i);//for shift body
          snake.set_y(i);//for shift body
          body_shape[i - 1].setPosition(snake.get_location_x(i) * 40, snake.get_location_y(i) * 40);
        }

        snake.set_location_x(0, 1);//for haed
        head_shape.setPosition(snake.get_location_x(0) * 40, snake.get_location_y(0) * 40);//for head
      }
      if (event.key.code == sf::Keyboard::Key::W)//North
      {
        for (size_t i = 1; i < snake.get_lenght(); i++)//for body
        {
          snake.set_x(i);//for shift body
          snake.set_y(i);//for shift body
          body_shape[i - 1].setPosition(snake.get_location_x(i) * 40, snake.get_location_y(i) * 40);
        }

        snake.set_location_y(0, -1);//for haed
        head_shape.setPosition(snake.get_location_x(0) * 40, snake.get_location_y(0) * 40);//for head
      }
      if (event.key.code == sf::Keyboard::Key::S)//South
      {
        for (size_t i = 1; i < snake.get_lenght(); i++)//for body
        {
          snake.set_x(i);//for shift body
          snake.set_y(i);//for shift body
          body_shape[i - 1].setPosition(snake.get_location_x(i) * 40, snake.get_location_y(i) * 40);
        }

        snake.set_location_y(0, 1);//for haed
        head_shape.setPosition(snake.get_location_x(0) * 40, snake.get_location_y(0) * 40);//for head
      }
    }

    if (snake.get_location_x(0) > 20 or snake.get_location_x(0) < 0 or snake.get_location_y(0) > 20 or snake.get_location_y(0) < 0)
    {
      writefile(name, f_count*10);
      return;
    }

    if (snake.get_location_x(0) == food.get_foodlocx() && snake.get_location_y(0) == food.get_foodlocy())//if location of snake head and food equaled(snake eat apple)
    {
      snake.grow_up();//function in snake class for increase body length
      b1.setPosition(snake.get_location_x(snake.get_lenght()) * 40, snake.get_location_y(snake.get_lenght()) * 40);
      body_shape.push_back(b1);

      f_count++;//apple count += 1
      food.new_food();//new food random
      spr_food.setPosition(food.get_foodlocx() * 40, food.get_foodlocy() * 40);
    }

    window.clear();
    window.draw(back_sprite);//to show background photo
    for (size_t i = 0; i < body_shape.size(); i++)
    {
      window.draw(body_shape[i]);//to show snake body
    }
    window.draw(spr_food);//to show food
    window.draw(head_shape);//to show snake head
    window.display();//action
  }
  cout << name << ", your score is: " << f_count << endl;
  writefile(name, f_count*10);
}

Game::Game()
{

}