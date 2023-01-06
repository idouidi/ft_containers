/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tester.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:23:15 by idouidi           #+#    #+#             */
/*   Updated: 2023/01/06 16:38:57 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include  "../../../includes/ftnspace.hpp"

void constructor_tester();

void vector_tester()
{
    mkdir("./srcs/vector/output", 0777);
    std::srand(time(NULL));

    STD !=  1 ?  std::cout<< "\n\033[1;31m             = = =>      VECTOR      <= = =\033[0m\n\n" : 0;
    STD !=  1 ?  std::cout<< "\033[1;33m + CONSTRUCTOR + \033[0m\n" : 0;
    
    constructor_tester();

    // std::cout<< "\n\033[1;33m + ITERATOR + \033[0m\n";
    // {
    //    int         randArray[5];

    //    for(int i = 0; i < 5; i++)
    //        randArray[i]=rand()%100;

    //    std::vector<int>::iterator stl_it(&randArray[0]);
    //    ft::vector<int>::iterator ft_it(&randArray[0]);

    //    std::vector<int> stl_vector(stl_it, stl_it + 5);
    //    ft::vector<int> ft_vector(ft_it, ft_it + 5);

    //    compareIterator("./srcs/vector/output/Iterator", stl_vector, ft_vector);
    // }
    
    // std::cout << "\n\033[1;33m + CAPACITY + \033[0m\n";
    // {
    //     int             size = 4;
    //     int             randArray[size];
    //     const char      *ret; 
    //     std::fstream    os;

    //     os.open("./srcs/vector/output/Capacity", std::fstream::in | std::fstream::out |  std::ios_base::app);

    //     for(int i = 0; i < size; i++)
    //         randArray[i]=rand()%100;

    //     std::vector<int>::iterator stl_it(&randArray[0]);
    //     ft::vector<int>::iterator ft_it(&randArray[0]);
 
    //     std::vector<int> stl_vector(stl_it, stl_it + size);
    //     ft::vector<int> ft_vector(ft_it, ft_it + size);

    //     /* ORIGINAL STATE */
    //     os << "\n            ++ ORIGINAL STATE ++\n\n" << std::endl;
    //     printContent("./srcs/vector/output/Capacity", "STL", stl_vector);
    //     printContent("./srcs/vector/output/Capacity", "FT", ft_vector);

    //     std::cout << "SIZE:                  " <<((stl_vector.size() == ft_vector.size()) ? OK : KO) << std::endl; 
    //     std::cout << "MAXSIZE:               " <<((stl_vector.max_size() == ft_vector.max_size()) ? OK : KO) << std::endl;     
    //     std::cout << "CAPACITY               " <<((stl_vector.capacity() == ft_vector.capacity()) ? OK : KO) << std::endl; 
    //     std::cout << "EMPTY:                 " <<((stl_vector.empty() == ft_vector.empty()) ? OK : KO) << std::endl; 

    //     /* RESIZE WITH N < SIZE() */
    //     os << "\n            ++ RESIZE WITH N < SIZE() ++\n\n" << std::endl;
    //     stl_vector.resize(2);
    //     ft_vector.resize(2);
    //     printContent("./srcs/vector/output/Capacity", "STL", stl_vector);
    //     printContent("./srcs/vector/output/Capacity", "FT", ft_vector);

    //     ret = (*stl_vector.begin() == *ft_vector.begin() ? OK : KO);
    //     ret = (*(stl_vector.end() - 1) == *(ft_vector.end() - 1) ? OK : KO);
    //     std::cout << "RESIZE:                " << (!std::strcmp(ret, OK) ? OK : KO) << " ";

    //     /* RESIZE WITH N > SIZE() */
    //     os << "\n            +++ RESIZE WITH N > SIZE() +++\n\n" << std::endl;
    //     stl_vector.resize(10);
    //     ft_vector.resize(10);
    //     printContent("./srcs/vector/output/Capacity", "STL", stl_vector);
    //     printContent("./srcs/vector/output/Capacity", "FT", ft_vector);

    //     ret = (*stl_vector.begin() == *ft_vector.begin() ? OK : KO);
    //     ret = (*(stl_vector.end() - 1) == *(ft_vector.end() - 1) ? OK : KO);
    //     std::cout << (!std::strcmp(ret, OK) ? OK : KO) << std::endl;

    //     /* RESERVE WITH N > CAPACITY */
    //     os << "\n            +++ RESERVE N > CAPACITY() +++\n\n" << std::endl;
    //     stl_vector.reserve(20);
    //     ft_vector.reserve(20);
    //     printContent("./srcs/vector/output/Capacity", "STL", stl_vector);
    //     printContent("./srcs/vector/output/Capacity", "FT", ft_vector);
    //     std::cout << "RESERVE:               " << ((stl_vector.capacity() == ft_vector.capacity()) ? OK : KO) << " ";
        
    //     /* RESERVE WITH N < CAPACITY */
    //     os << "\n            +++ RESERVE N < CAPACITY() +++\n\n" << std::endl;
    //     stl_vector.reserve(3);
    //     ft_vector.reserve(3);
    //     printContent("./srcs/vector/output/Capacity", "STL", stl_vector);
    //     printContent("./srcs/vector/output/Capacity", "FT", ft_vector);
    //     std::cout << ((stl_vector.capacity() == ft_vector.capacity()) ? OK : KO) << std::endl;
    //     os.close();
    // }

    // std::cout << "\n\033[1;33m + ELEMENT ACCESS + \033[0m\n";
    // {
    //     int             size = 5;
    //     int             randArray[size];

    //     for(int i = 0; i < size; i++)
    //         randArray[i]=rand()%100;

    //     std::vector<int>::iterator stl_it(&randArray[0]);
    //     ft::vector<int>::iterator ft_it(&randArray[0]);

    //     std::vector<int> stl_vector(stl_it, stl_it + size);
    //     ft::vector<int> ft_vector(ft_it, ft_it + size);

    //     printContent("./srcs/vector/output/Elem_access", "STL", stl_vector);
    //     printContent("./srcs/vector/output/Elem_access", "FT", ft_vector);
    //     compareElemAccess("./srcs/vector/output/Elem_access", stl_vector, ft_vector);
    // }

    // std::cout << "\n\033[1;33m + MODIFIERS + \033[0m\n";
    // {
    //     int             size = 15;
    //     int             randArray[size];
    //     std::fstream    os;

    //     os.open("./srcs/vector/output/Assign_range", std::fstream::in | std::fstream::out |  std::ios_base::app);
  
    //     for(int i = 0; i < size; i++)
    //         randArray[i]=rand()%100;

    //     std::vector<int>::iterator stl_it(&randArray[0]);
    //     ft::vector<int>::iterator ft_it(&randArray[0]);
        
    //     std::vector<int> stl_vector(stl_it, stl_it + size);
    //     ft::vector<int> ft_vector(ft_it, ft_it + size);

    //     /* ORIGINAL STATE */
    //     os << "\n            ++ ORIGINAL STATE ++\n\n" << std::endl;
    //     compareContent("./srcs/vector/output/Assign_range", stl_vector, ft_vector);

    //     /*ASSIGN RANGE VERSION */
    //     os << "\n            ++ ASSIGN RANGE VERSION ++\n\n" << std::endl;
    //     stl_vector.assign(stl_it + 3, stl_it + 9);
    //     ft_vector.assign(stl_it + 3, stl_it + 9);
    //     compareContent("./srcs/vector/output/Assign_range", stl_vector, ft_vector);
    //     os.close();
    // }
}
