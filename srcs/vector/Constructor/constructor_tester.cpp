/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor_tester.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:30:36 by idouidi           #+#    #+#             */
/*   Updated: 2022/12/29 20:56:19 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/vector.hpp"

#if STD == 1
   std::string __name_space__ = "std";
#else
  std::string __name_space__ = "ft"; 
#endif

int compareFile(FILE* f1, FILE* f2) {
  int N = 10000;
  char buf1[N];
  char buf2[N];

  do {
    size_t r1 = fread(buf1, 1, N, f1);
    size_t r2 = fread(buf2, 1, N, f2);

    if (r1 != r2 ||
        memcmp(buf1, buf2, r1)) {
      return 0;
    }
  } while (!feof(f1) || !feof(f2));

  return 1;
}

void constructor_tester()
{


     std::cout<< "Default Constructor:   ";
    {
        mkdir("./srcs/vector/Constructor/default_constructor", 0777);

        std::string file_name = "./srcs/vector/Constructor/default_constructor/" + __name_space__ + "_default_constructor" + ".diff";
        
        NAMESPACE::vector<int> vec;

        printContent(file_name.c_str(), vec);
        if (STD == 1)
        {
            FILE *f1 = std::fopen("./srcs/vector/Constructor/default_constructor/std_default_constructor.diff", "r");
            FILE *f2 = std::fopen("./srcs/vector/Constructor/default_constructor/ft_default_constructor.diff", "r");
            std::cout << (compareFile(f1, f2) ? OK : KO) << std::endl;
        }
        
        // std::cout << (compareContent("./srcs/vector/Constructor/output/Default_constructor", stl_vector, ft_vector))<< std::endl;

    }

    // std::cout<< "Fill Constructor:      ";
    // {
    //     std::vector<int> stl_vector(7);
    //     ft::vector<int> ft_vector(7);
    //     std::cout << (compareContent("./srcs/vector/Constructor/output/Fill_constructor", stl_vector, ft_vector))<< " ";

    //     std::vector<int> stl_vector_val(7, 42);
    //     ft::vector<int> ft_vector_val(7, 42);
    //     std::cout << (compareContent("./srcs/vector/Constructor/output/Fill_constructor", stl_vector_val, ft_vector_val))<< std::endl;
    // }

    // std::cout<< "Range Constructor:     ";
    // {
    //     int randArray[5];
        
    //     for(int i = 0; i < 5; i++)
    //         randArray[i]=rand()%100;

    //     std::vector<int>::iterator stl_it(&randArray[2]);
    //     ft::vector<int>::iterator ft_it(&randArray[2]);
    
    //     std::vector<int> stl_vector(stl_it, stl_it + 3);
    //     ft::vector<int> ft_vector(ft_it, ft_it + 3);
    //     std::cout << (compareContent("./srcs/vector/Constructor/output/Range_constructor", stl_vector, ft_vector))<< std::endl;
    // }
    
    // std::cout<< "Copy Constructor:      ";
    // {
    //     int randArray[5];

    //     for(int i = 0; i < 5; i++)
    //         randArray[i]=rand()%100;

    //     std::vector<int>::iterator stl_it(&randArray[0]);
    //     ft::vector<int>::iterator ft_it(&randArray[0]);
    
    //     std::vector<int> stl_vector(stl_it, stl_it + 5);
    //     ft::vector<int> ft_vector(ft_it, ft_it + 5);

    //     std::vector<int> stl_vector_copy(stl_vector);
    //     ft::vector<int> ft_vector_copy(ft_vector);
    //     if (!std::strcmp(compareContent("./srcs/vector/Constructor/output/Copy_constructor", stl_vector, ft_vector) , OK ) && (ft_vector == ft_vector_copy))
    //         std::cout << OK << std::endl;
    //     else
    //         std::cout << KO << std::endl;
    // }
}