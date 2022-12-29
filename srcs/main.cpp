/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:59:59 by idouidi           #+#    #+#             */
/*   Updated: 2022/12/29 21:37:30 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/ftnspace.hpp"

int compareFile(FILE* f1, FILE* f2)
{
  int size = 10000;
  char buf1[size];
  char buf2[size];

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
    vector_tester();
    return (0);
}
