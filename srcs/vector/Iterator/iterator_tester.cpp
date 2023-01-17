/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_tester.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:35:14 by idouidi           #+#    #+#             */
/*   Updated: 2023/01/17 20:42:21 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/ftnspace.hpp"

void vector_iterator_tester()
{
    STD !=  1 ?  std::cout<< YELLOW <<" + CAPACITY +  " << RESET << std::endl : 0;

    std::string path = "./srcs/vector/Iterator/";
    std::fstream os;

    /* BEGIN */
    {
        mkdir("./srcs/vector/Iterator/begin", 0777);
        std::string filename = path + "begin/" + __NAME_SPACE__ + "_begin" + ".diff";
		std::string filetime = path + "begin/time.diff";

        os.open(filename.c_str(), std::fstream::in | std::fstream::out |  std::ios_base::app);
        if (!os.is_open()) 
        {
            std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
            exit(EXIT_FAILURE);
        }
        NAMESPACE::vector<int> vec;

	    for(int i = 0; i < 5; i++)
            vec.push_back(i + (42 * 10));
        
        /* 📌 */  NAMESPACE::vector<int>::iterator it(vec.begin());

        os << "#    #   #   #   #   #   #   #   #   #   #   #   #"<<std::endl; 
        os << "BEGIN = [" << *it << "]" << std::endl;
        os << "clear all elements" << std::endl;
        /* 📌 */ vec.clear();
        os << "BEGIN = [" << *it << "]" << std::endl;
        os << "#    #   #   #   #   #   #   #   #   #   #   #   #"<<std::endl;
        printTime(filetime.c_str());

        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Iterator/begin/std_begin.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Iterator/begin/ft_begin.diff", "r");

			std::cout << "Begin:                          " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);
		}
        os.close();
    }

    /* END */
    {
        mkdir("./srcs/vector/Iterator/end", 0777);
        std::string filename = path + "end/" + __NAME_SPACE__ + "_end" + ".diff";
		std::string filetime = path + "end/time.diff";

        os.open(filename.c_str(), std::fstream::in | std::fstream::out |  std::ios_base::app);
        if (!os.is_open()) 
        {
            std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
            exit(EXIT_FAILURE);
        }
        NAMESPACE::vector<int> vec;

	    for(int i = 0; i < 5; i++)
            vec.push_back(i + (42 * 10));
        
        /* 📌 */  NAMESPACE::vector<int>::iterator ite(vec.end() - 1);

        os << "#    #   #   #   #   #   #   #   #   #   #   #   #"<<std::endl; 
        os << "END = [" << *ite << "]" << std::endl;
        os << "clear all elements" << std::endl;
        /* 📌 */ vec.clear();
        os << "END = [" << *ite << "]" << std::endl;
        os << "#    #   #   #   #   #   #   #   #   #   #   #   #"<<std::endl;
        printTime(filetime.c_str());

        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Iterator/end/std_end.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Iterator/end/ft_end.diff", "r");

			std::cout << "End:                            " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);
		}
        os.close();
    }

    /* RBEGIN */
    {
        mkdir("./srcs/vector/Iterator/rbegin", 0777);
        std::string filename = path + "rbegin/" + __NAME_SPACE__ + "_rbegin" + ".diff";
		std::string filetime = path + "rbegin/time.diff";

        os.open(filename.c_str(), std::fstream::in | std::fstream::out |  std::ios_base::app);
        if (!os.is_open()) 
        {
            std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
            exit(EXIT_FAILURE);
        }
        NAMESPACE::vector<int> vec;

	    for(int i = 0; i < 5; i++)
            vec.push_back(i + (42 * 10));

        printIterator(os, vec);
        printTime(filetime.c_str());

        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Iterator/rbegin/std_rbegin.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Iterator/rbegin/ft_rbegin.diff", "r");

			std::cout << "Rbegin:                         " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);
		}
        os.close();
    }

    /* REND */
    {
        mkdir("./srcs/vector/Iterator/rend", 0777);
        std::string filename = path + "rend/" + __NAME_SPACE__ + "_rend" + ".diff";
		std::string filetime = path + "rend/time.diff";

        os.open(filename.c_str(), std::fstream::in | std::fstream::out |  std::ios_base::app);
        if (!os.is_open()) 
        {
            std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
            exit(EXIT_FAILURE);
        }
        NAMESPACE::vector<int> vec;

	    for(int i = 0; i < 5; i++)
            vec.push_back(i + (42 * 10));

        printIterator(os, vec);
        printTime(filetime.c_str());

        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Iterator/rend/std_rend.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Iterator/rend/ft_rend.diff", "r");

			std::cout << "Rend:                           " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);
		}
        os.close();
    }



}