//
// Parser.cpp for Parser in /home/chen_c/rendu/piscine_cpp_d16
// 
// Made by Billy CHEN
// Login   <chen_c@epitech.net>
// 
// Started on  Thu Jan 23 11:09:14 2014 Billy CHEN
// Last update Thu Jan 23 17:48:06 2014 Billy CHEN
//

#include "Parser.h"
#include <string>
#include <sstream>
#include <cstdlib>
#include <iostream>

Parser::Parser()
{
  
}

Parser::~Parser()
{
  
}

void		Parser::feed(const std::string & exp)
{
  
}

int		Parser::result() const
{
  
}

void		Parser::reset()
{
  
}

void		Parser::push_number(std::string exp, int &i)
{
  std::string	number;
  int		num;
  
  while (exp.at(i) >= 48 && exp.at(i) <= 57)
    {
      number += exp.at(i);
      i = i + 1;
    }
  num = atoi(number.c_str());
  this->operande.push(num);
}

void		Parser::push_operator(char c)
{
  std::ostringstream	num;
  int			pos;

  pos = this->expr.length();
  if (this->operators.top() == '(' || this->operators.empty() == true)
    this->operators.push(c);
    else
    {
      if (c == '*' || c == '/' || c == '%')
	{
	  if (this->operators.top() == '+' || this->operators.top() == '-')
	    this->operators.push(c);
	  else
	    {
	      while (this->operande.empty() != true)
		{
		  num << this->operande.top();
		  this->expr.insert(pos, num.str() + ' ');
		  this->operande.pop();
		}
	      this->expr += this->operators.top();
	      this->operators.pop();
	      this->operators.push(c);
	    }
	}
      else if (c == '+' || c == '-')
	{
	  while (this->operande.empty() != true)
	    {
	      num << this->operande.top();
	      this->expr.insert(pos, num.str() + ' ');
	      this->operande.pop();
	    }
	  this->expr += this->operators.top();
	  this->operators.pop();
	  this->operators.push(c);
	}
    }
}

void		Parser::depile()
{
  std::ostringstream	num;
  int			pos;
  
  pos = this->expr.length();
  while (!this->operande.empty())
    {
      num << this->operande.top();
      this->expr.insert(pos, num.str() + ' ');
      this->operande.pop();
    }
  while (this->operators.top() != '(' || this->operators.empty() != true)
    {
      this->expr += this->operators.top();
      this->operators.pop();
    }
  if (this->operators.top() == '(')
    {
      while (this->operators.top() != '(')
	{
	  this->operators.pop();
	}
    }
}

void			Parser::convert_to_npi(std::string exp)
{
  int		i;
  std::string	all_operator;

  all_operator = "+/%*-";
  i = 0;
  while (i < exp.length())
    {
      if (exp.at(i) == '(')
	this->operators.push('(');
      else if (exp.at(i) >= 48 && exp.at(i) <= 57)
	{
	  push_number(exp, i);
	}
      else if (exp.at(i) == ')')
	{
	  depile();
	}
      else if (all_operator.find(exp.at(i)) != std::string::npos)
	{
	  push_operator(exp.at(i));
	}
      i = i + 1;
      std::cout << i << std::endl;
    }
}
