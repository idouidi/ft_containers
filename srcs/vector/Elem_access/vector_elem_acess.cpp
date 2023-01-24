/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_elem_acess.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:51:31 by idouidi           #+#    #+#             */
/*   Updated: 2023/01/24 14:13:46 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/ftnspace.hpp"

void vector_elem_access_tester()
{
    if (STD != 1)
        std::cout<< YELLOW <<" + ELEM ACESS +  " << RESET << std::endl;

    std::string path = "./srcs/vector/Elem_access/";
    std::fstream os;

    /* OPERATOR */
    {
        mkdir("./srcs/vector/Elem_access/operator", 0777);
        std::string filename = path + "operator/" + __NAME_SPACE__ + "_operator" + ".diff";
	    std::string filetime = path + "operator/time.diff";

        os.open(filename.c_str(), std::fstream::in | std::fstream::out |  std::ios_base::app);
        if (!os.is_open()) 
        {
            std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
            exit(EXIT_FAILURE);
        }

        NAMESPACE::vector<int> vec;

	    for(int i = 0; i < 10; i++)
        {
            vec.push_back(i + (i *42));
        /* 📌 */    os << "OPERATOR[" << i << "] = " << vec[i] << std::endl;
        }

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

    /* AT */
    {
        mkdir("./srcs/vector/Elem_access/at", 0777);
        std::string filename = path + "at/" + __NAME_SPACE__ + "_at" + ".diff";
	    std::string filetime = path + "at/time.diff";

        os.open(filename.c_str(), std::fstream::in | std::fstream::out |  std::ios_base::app);
        if (!os.is_open()) 
        {
            std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
            exit(EXIT_FAILURE);
        }

        NAMESPACE::vector<int> vec;

	    for(int i = 0; i < 10; i++)
        {
            vec.push_back(i + (i *42));
        /* 📌 */    os << "at[" << i << "] = " << vec.at(i) << std::endl;
        }

        printTime(filetime.c_str());

        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Elem_access/at/std_at.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Elem_access/at/ft_at.diff", "r");

			std::cout << "AT:                             " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);
		}
        os.close();
    }

    /* FRONT */
    {
        mkdir("./srcs/vector/Elem_access/front", 0777);
        std::string filename = path + "front/" + __NAME_SPACE__ + "_front" + ".diff";
	    std::string filetime = path + "front/time.diff";

        os.open(filename.c_str(), std::fstream::in | std::fstream::out |  std::ios_base::app);
        if (!os.is_open()) 
        {
            std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
            exit(EXIT_FAILURE);
        }

        NAMESPACE::vector<int> vec;

	    for(int i = 0; i < 10; i++)
            vec.push_back(i + (i *42));

        for (int i =0; i < 10 ; i++)
        {
        /* 📌 */    os << "Front value is [" << vec.front() << "]" << std::endl;
            vec.erase(vec.begin());
        }

        printTime(filetime.c_str());

        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Elem_access/front/std_front.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Elem_access/front/ft_front.diff", "r");

			std::cout << "FRONT:                          " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);
		}
        os.close();
    }

    /* BACK */
    {
        mkdir("./srcs/vector/Elem_access/back", 0777);
        std::string filename = path + "back/" + __NAME_SPACE__ + "_back" + ".diff";
	    std::string filetime = path + "back/time.diff";

        os.open(filename.c_str(), std::fstream::in | std::fstream::out |  std::ios_base::app);
        if (!os.is_open()) 
        {
            std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
            exit(EXIT_FAILURE);
        }

        NAMESPACE::vector<int> vec;

	    for(int i = 0; i < 10; i++)
            vec.push_back(i + (i *42));

        for (int i =0; i < 10 ; i++)
        {
        /* 📌 */    os << "Back value is [" << vec.back() << "]" << std::endl;
            vec.pop_back();
        }

        printTime(filetime.c_str());

        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Elem_access/back/std_back.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Elem_access/back/ft_back.diff", "r");

			std::cout << "BACK:                           " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);
		}
        os.close();
    }

    /* DATA */
    {
        mkdir("./srcs/vector/Elem_access/data", 0777);
        std::string filename = path + "data/" + __NAME_SPACE__ + "_data" + ".diff";
	    std::string filetime = path + "data/time.diff";

        os.open(filename.c_str(), std::fstream::in | std::fstream::out |  std::ios_base::app);
        if (!os.is_open()) 
        {
            std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
            exit(EXIT_FAILURE);
        }

        NAMESPACE::vector<int> vec(5);

        /* 📌 */ int* data = vec.data();

        *data = 10;
        ++data;
        *data = 20;
        data[2] = 100;

        for (int i =0; i < 5 ; i++)
           os << "the ptr Data value at the position [" << i << "] = " << vec[i] << std::endl;

        printTime(filetime.c_str());

        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Elem_access/data/std_data.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Elem_access/data/ft_data.diff", "r");

			std::cout << "DATA:                           " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);
		}
        os.close();
    }
}
