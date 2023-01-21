/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_non_member_func.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:35:35 by idouidi           #+#    #+#             */
/*   Updated: 2023/01/21 18:00:23 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/ftnspace.hpp"

void vector_non_member_func_tester()
{
    if (STD != 1)
        std::cout<< YELLOW <<" + NON MEMBER FUNC +  " << RESET << std::endl;
    
    std::string path = "./srcs/vector/Non_member_func/";
    std::fstream os;

    /* RELATIONAL OPERATOR */
    {
        mkdir("./srcs/vector/Non_member_func/relational_operator/", 0777);
        std::string filename = path + "relational_operator/" + __NAME_SPACE__ + "_relational_operator" + ".diff";
	    std::string filetime = path + "relational_operator/time.diff";

        os.open(filename.c_str(), std::fstream::in | std::fstream::out |  std::ios_base::app);
        if (!os.is_open()) 
        {
            std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
            exit(EXIT_FAILURE);
        }

        NAMESPACE::vector<int> foo (3,100);  
        NAMESPACE::vector<int> bar (2,200);  
        
        if (foo==bar) os << "foo and bar are equal" << std::endl;
        if (foo!=bar) os << "foo and bar are not equal" << std::endl;
        if (foo< bar) os << "foo is less than bar" << std::endl;
        if (foo> bar) os << "foo is greater than bar" << std::endl;
        if (foo<=bar) os << "foo is less than or equal to bar" << std::endl;
        if (foo>=bar) os << "foo is greater than or equal to b" << std::endl;

        printTime(filetime.c_str());

        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Non_member_func/relational_operator/std_relational_operator.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Non_member_func/relational_operator/ft_relational_operator.diff", "r");

			std::cout << "RELATIONAL OPERATOR:            " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);
		}
        os.close();
    }

    /* SWAP */
    {
        mkdir("./srcs/vector/Non_member_func/swap/", 0777);
        std::string filename = path + "swap/" + __NAME_SPACE__ + "_swap" + ".diff";
	    std::string filetime = path + "swap/time.diff";

        NAMESPACE::vector<int> first(10, 42);
        NAMESPACE::vector<int> second(10, 77);

        printContent(filename.c_str(), "FIRST VEC", first);
        printContent(filename.c_str(), "SECOND VEC", second);

        /* 📌 Non-member function overloads*/
        swap(first, second);
        printContent(filename.c_str(), "NON MEMBER FUNC SWAP: FIRST", first);
        printContent(filename.c_str(), "NON MEMBER FUNC SWAP: SECOND", second);
        printTime(filetime.c_str());

        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Non_member_func/swap/std_swap.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Non_member_func/swap/ft_swap.diff", "r");

			std::cout << "SWAP:                           " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);
		}
    }
}