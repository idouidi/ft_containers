/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor_tester.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:30:36 by idouidi           #+#    #+#             */
/*   Updated: 2022/12/26 20:34:30 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../utils_vector.hpp"

void constructor_tester()
{
        mkdir("./srcs/vector/Constructor/output", 0777);

        std::cout<< "Default Constructor:   ";
    {
        std::vector<int> stl_vector;
        ft::vector<int> ft_vector;
        std::cout << (compareContent("./srcs/vector/Constructor/output/Default_constructor", stl_vector, ft_vector))<< std::endl;
    }

    std::cout<< "Fill Constructor:      ";
    {
        std::vector<int> stl_vector(7);
        ft::vector<int> ft_vector(7);
        std::cout << (compareContent("./srcs/vector/Constructor/output/Fill_constructor", stl_vector, ft_vector))<< " ";

        std::vector<int> stl_vector_val(7, 42);
        ft::vector<int> ft_vector_val(7, 42);
        std::cout << (compareContent("./srcs/vector/Constructor/output/Fill_constructor", stl_vector_val, ft_vector_val))<< std::endl;
    }

    std::cout<< "Range Constructor:     ";
    {
        int randArray[5];
        
        for(int i = 0; i < 5; i++)
            randArray[i]=rand()%100;

        std::vector<int>::iterator stl_it(&randArray[2]);
        ft::vector<int>::iterator ft_it(&randArray[2]);
    
        std::vector<int> stl_vector(stl_it, stl_it + 3);
        ft::vector<int> ft_vector(ft_it, ft_it + 3);
        std::cout << (compareContent("./srcs/vector/Constructor/output/Range_constructor", stl_vector, ft_vector))<< std::endl;
    }
    
    std::cout<< "Copy Constructor:      ";
    {
        int randArray[5];

        for(int i = 0; i < 5; i++)
            randArray[i]=rand()%100;

        std::vector<int>::iterator stl_it(&randArray[0]);
        ft::vector<int>::iterator ft_it(&randArray[0]);
    
        std::vector<int> stl_vector(stl_it, stl_it + 5);
        ft::vector<int> ft_vector(ft_it, ft_it + 5);

        std::vector<int> stl_vector_copy(stl_vector);
        ft::vector<int> ft_vector_copy(ft_vector);
        if (!std::strcmp(compareContent("./srcs/vector/Constructor/output/Copy_constructor", stl_vector, ft_vector) , OK ) && (ft_vector == ft_vector_copy))
            std::cout << OK << std::endl;
        else
            std::cout << KO << std::endl;
    }
}