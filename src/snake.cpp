#include "snake.hpp"
#include "snake.hpp"
#include <iostream>

Snake::Snake()
{
  location.push_back({10, 15});//default head mod
  location.push_back({11, 15});//default body part 1
}

void Snake::set_location_x(int i, int u)
{
  location[i].x = (location[i].x) + u;//for shift body partition
}

void Snake::set_location_y(int i, int u)
{
  location[i].y = (location[i].y) + u;//for shift body partition
}

void Snake::set_length(int len)
{
  length = len;
}

int Snake::get_lenght()
{
  return length;
}

int Snake::get_location_x(int i)
{
  int xreturned;
  xreturned = location[i].x;
  return xreturned;
}

int Snake::get_location_y(int i)
{
  int xreturned;
  xreturned = location[i].y;
  return xreturned;
}

void Snake::set_x(int num)
{
  location[num].x = location[num-1].x;

}

void Snake::set_y(int num)
{
  location[num].y = location[num-1].y;
}

std::vector<Snakeloc>* Snake::get_vector()//for return snake vector
{
  return &location;
}

void Snake::grow_up()
{
  int x;
  int y;
  if (location[0].x == location[1].x)
  {
    x = location[0].x;
    if (location[0].y > location[1].y)
      y = location[0].y + 1;
    else
      y = location[0].y - 1;
  }
  else
  {
    y = location[0].y;
    if (location[0].x > location[1].x)
      x = location[0].x + 1;
    else
      x = location[0].x - 1;
  }
  
  location.insert(location.begin(), 1, {x,y}); 
}