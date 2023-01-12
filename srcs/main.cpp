/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:59:59 by idouidi           #+#    #+#             */
/*   Updated: 2023/01/12 14:16:55 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/ftnspace.hpp"

std::string __name_space__;


int compareFile(FILE* f1, FILE* f2)
{
  int size = 10000;
  char buf1[size];
  char buf2[size];

  if (!f1|| !f2)
  {
    std::cerr << RED << "\n /!\\ YOU HAVE A PROBLEM WITH YOUR FILES, CHECK THEIR VALIDITY" << RESET << std::endl;
    exit (1);
  }

  do 
  {
    size_t r1 = std::fread(buf1, 1, size, f1);
    size_t r2 = std::fread(buf2, 1, size, f2);

    if (r1 != r2 ||
        std::memcmp(buf1, buf2, r1)) {
      return (0);
    }
  }
  while (!feof(f1) || !feof(f2));
  return (1);
}

int main()
{
    __name_space__ = (STD == 1) ? "std" : "ft" ;
    vector_tester();

    return (0);
}
