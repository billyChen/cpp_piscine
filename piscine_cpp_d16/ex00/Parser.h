/*
** Parser.h for Parser in /home/chen_c/rendu/piscine_cpp_d16
** 
** Made by Billy CHEN
** Login   <chen_c@epitech.net>
** 
** Started on  Thu Jan 23 11:05:13 2014 Billy CHEN
** Last update Thu Jan 23 17:28:48 2014 Billy CHEN
*/

#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <stack>

class		Parser
{
 public:
  Parser();
  ~Parser();
  void		feed(const std::string &);
  int		result() const;
  void		reset();
  void		convert_to_npi(std::string);
  std::string	expr;

 private:
  void		push_number(std::string, int &);
  void		push_operator(char);
  void		depile(void);
  std::stack<int> operande;
  std::stack<char> operators;
};

#endif /* PARSER_H */
