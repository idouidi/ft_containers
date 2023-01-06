/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor_tester.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:30:36 by idouidi           #+#    #+#             */
/*   Updated: 2023/01/06 17:03:40 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/ftnspace.hpp"

void constructor_tester()
{

    /* DEFAULT CONSTRUCTOR */
    STD != 1 ? std::cout<< "Default Constructor:   " : 0;
    {
        mkdir("./srcs/vector/Constructor/default_constructor", 0777);

        std::string file_name = "./srcs/vector/Constructor/default_constructor/" + __name_space__ + "_default_constructor" + ".diff";
        
        NAMESPACE::vector<int> vec;

        printContent(file_name.c_str(), vec);
        if (STD != 1)
        {
            FILE *f1 = std::fopen("./srcs/vector/Constructor/default_constructor/std_default_constructor.diff", "r");
            FILE *f2 = std::fopen("./srcs/vector/Constructor/default_constructor/ft_default_constructor.diff", "r");
            std::cout << (compareFile(f1, f2) ? OK : KO) << std::endl;
        }
        
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