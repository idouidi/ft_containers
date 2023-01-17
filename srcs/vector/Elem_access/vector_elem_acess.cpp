/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_elem_acess.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:51:31 by idouidi           #+#    #+#             */
/*   Updated: 2023/01/17 21:11:23 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/ftnspace.hpp"

void vector_elem_access_tester()
{
    STD !=  1 ?  std::cout<< YELLOW <<" + ELEMENT ACCESS +  " << RESET << std::endl : 0;

    std::string path = "./srcs/vector/Elem_access/";
    std::fstream os;

    /* OPERATOR */
    {
        mkdir("./srcs/vector/Elem_access/operator  ", 0777);
        std::string filename = path + "operator/" + __NAME_SPACE__ + "_operator" + ".diff";
	    std::string filetime = path + "operator/time.diff";

        os.open(filename.c_str(), std::fstream::in | std::fstream::out |  std::ios_base::app);
        if (!os.is_open()) 
        {
            std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
            exit(EXIT_FAILURE);
        }

        NAMESPACE::vector<int> vec;

	    for(int i = 0; i < 20; i++)
        {
            vec.push_back(i + (i *42));
            os << "OPERATOR[" << i << "]" << vec[i];
        }
        os << std::endl;

        printTime(filetime.c_str());

        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Elem_access/operator/std_operator.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Elem_access/operator/ft_operator.diff", "r");

			std::cout << "OPERATOR:                       " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);
		}
        os.close();



    }
}