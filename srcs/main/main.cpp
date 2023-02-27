/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:59:59 by idouidi           #+#    #+#             */
/*   Updated: 2023/02/27 23:28:06 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../includes/ftnspace.hpp"

std::string   __NAME_SPACE__;
unsigned long __CURRENT_TIME__;

long	t_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

unsigned long	current_time()
{
	return (t_time() - __CURRENT_TIME__);
}

int compareFile(FILE* f1, FILE* f2)
{
  int size = 10000;
  char buf1[size];
  char buf2[size];

  if (!f1|| !f2)
  {
    std::cerr << RED << "\n /!\\ YOU HAVE A PROBLEM WITH YOUR FILES, \
CHECK THEIR VALIDITY" << RESET << std::endl;
    exit (1);
  }

  do 
  {
    size_t r1 = std::fread(buf1, 1, size, f1);
    size_t r2 = std::fread(buf2, 1, size, f2);

    if (r1 != r2 || std::memcmp(buf1, buf2, r1))
      return (0);
  }
  while (!feof(f1) || !feof(f2));
  return (1);
}

void  printTime(const char *filename)
{
  std::fstream os;
  os.open(filename, std::fstream::in | std::fstream::out |  std::ios_base::app);

  if (!os.is_open()) 
  {
      std::cerr << RED << "Could not open the file - '" << filename << "'" << RESET << std::endl;
      exit(EXIT_FAILURE);
  }

  os << "TIME ("<< __NAME_SPACE__ << ") = " << current_time() << " ms" <<std::endl;
  os.close();
}

bool compareTime(const char *filename)
{
  std::ifstream fd(filename);
  std::string str;
  int i = 0;
  unsigned long time[2] = {0, 0};
  unsigned long number;

  if (!fd.is_open()) 
  {
      std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
      return (EXIT_FAILURE);
  }
  while (fd.good())
  {
    fd >> str;
    if ((number = std::atoi(str.c_str())) && i < 2)
      time[i++] = number;
  }
  fd.close();
  if (time[0] == 0)
    time[0] = 1;
  return (time[0] * 20 >= time[1]);
}

int main()
{
    __CURRENT_TIME__ = t_time();
    __NAME_SPACE__ = (STD == 1) ? "std" : "ft" ;
    // vector_tester();
    // stack_tester();

std::cout << RED << "--> " << __NAME_SPACE__ << "<--" << RESET << std::endl;

if (STD != 1)
{

    // ft::map<int, std::string> test;
    // test.insert(ft::pair<int, std::string>(1, "bar"));

    ft::map<int, int>::iterator it;
    ft::map<int, int>::iterator ite;


    ft::map<int, int> long_map;

    for (int i = 0; i < 42; i++)
    {
      long_map.insert(ft::pair<int, int>(i , i * 2));
    }

      long_map.base().printAllRb_tree();
    long_map.erase(34);
      long_map.base().printAllRb_tree();

    // it = long_map.begin();
    // ite = long_map.end();
    // ite--;
      // while (it != ite)
      // {
      //   std::cout << it->first << ", " << it->second << '\n';
      //   it++;
      // }
}

  
  // if (STD != 1)
  // {
  //   ft::map<int, std::string> toPrint;
  //   toPrint.insert(ft::pair<int, std::string>(1, "salut"));
  //   toPrint.insert(ft::pair<int, std::string>(2, "bar"));
  //   toPrint.insert(ft::pair<int, std::string>(3, "foo"));
  //   toPrint.base().printTree();

    return (0);
}
