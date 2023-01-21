/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_modifiers_tester.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:22:35 by idouidi           #+#    #+#             */
/*   Updated: 2023/01/21 17:37:02 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/ftnspace.hpp"

void vector_modifiers_tester ()
{
    if (STD != 1)
        std::cout<< YELLOW <<" + MODIFIERS +  " << RESET << std::endl;

    std::string path = "./srcs/vector/Modifiers/";
    std::fstream os;

    /* ASSIGN */
    {
        mkdir("./srcs/vector/Modifiers/assign/", 0777);
        std::string filename = path + "assign/" + __NAME_SPACE__ + "_assign" + ".diff";
	    std::string filetime = path + "assign/time.diff";  
    
        NAMESPACE::vector<int> vec;

        /* 📌 FILL */        
        vec.assign(8,42);
        printContent(filename.c_str(), "FILL PART", vec);

        /* 📌 RANGE */
	    NAMESPACE::vector<int>::iterator it(vec.begin());
        vec.assign(it + 1, vec.end() - 2);
        printContent(filename.c_str(), "RANGE PART", vec);

        printTime(filetime.c_str());

        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Modifiers/assign/std_assign.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Modifiers/assign/ft_assign.diff", "r");

			std::cout << "ASSIGN:                         " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);
		}
    }

    /* PUSH_BACK*/
    {
        mkdir("./srcs/vector/Modifiers/push_back", 0777);
        std::string filename = path + "push_back/" + __NAME_SPACE__ + "_push_back" + ".diff";
	    std::string filetime = path + "push_back/time.diff";

        os.open(filename.c_str(), std::fstream::in | std::fstream::out |  std::ios_base::app);
        if (!os.is_open()) 
        {
            std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
            exit(EXIT_FAILURE);
        }
        NAMESPACE::vector<int> vec;

	    for(int i = 0; i < 5; i++)
        {
            vec.push_back(i + (i *10));
            os << "PUSH BACK THE VALUE [" << vec[i] << "] AT THE POSITION: " << i << std::endl; 
        }
        
        printTime(filetime.c_str());

        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Modifiers/push_back/std_push_back.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Modifiers/push_back/ft_push_back.diff", "r");

			std::cout << "PUSH_BACK:                      " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);
		}
        os.close();
    }

    /* POP_BACK*/
    {
        mkdir("./srcs/vector/Modifiers/pop_back", 0777);
        std::string filename = path + "pop_back/" + __NAME_SPACE__ + "_pop_back" + ".diff";
	    std::string filetime = path + "pop_back/time.diff";

        os.open(filename.c_str(), std::fstream::in | std::fstream::out |  std::ios_base::app);
        if (!os.is_open()) 
        {
            std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
            exit(EXIT_FAILURE);
        }
        NAMESPACE::vector<int> vec;

	    for(int i = 0; i < 5; i++)
            vec.push_back(i + (i *10));
	    for(int i = 5; i > 0; i--)
        {
            os << "POP BACK THE VALUE [" << vec[i - 1] << "] AT THE POSITION: " << i << std::endl; 
            vec.pop_back();
        }
        
        printTime(filetime.c_str());

        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Modifiers/pop_back/std_pop_back.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Modifiers/pop_back/ft_pop_back.diff", "r");

			std::cout << "POP_BACK:                       " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);
		}
        os.close();
    }

    /* INSERT */
    {
        mkdir("./srcs/vector/Modifiers/insert/", 0777);
        std::string filename = path + "insert/" + __NAME_SPACE__ + "_insert" + ".diff";
	    std::string filetime = path + "insert/time.diff";   
        
        NAMESPACE::vector<int> vec;
        for(int i = 0; i < 10; i++)
            vec.push_back(i + (i *42));
	    
        NAMESPACE::vector<int>::iterator it(vec.begin());

        /* 📌 INSERT AN ELEM */     
        vec.insert(it + 5, 123456789);
        printContent(filename.c_str(), "BASIC PART", vec);

        /* 📌 INSERT N ELEM */
        vec.insert(it, 5, 777);
        printContent(filename.c_str(), "INSERT N ELEM PART", vec);

        /* 📌 INSERT A RANGE OF ELEM */
        int tab[] = {42, 24, 4242, 2424, 4224, 2442};
        NAMESPACE::vector<int>::iterator it_tab(&(tab[0]));
        
        vec.insert(vec.end() - 1, it_tab, it_tab + 5 );
        printContent(filename.c_str(), "INSERT N ELEM PART", vec);

        printTime(filetime.c_str());

        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Modifiers/assign/std_assign.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Modifiers/assign/ft_assign.diff", "r");

			std::cout << "INSERT:                         " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);
		}
    }

    /* ERASE */
    {
        mkdir("./srcs/vector/Modifiers/erase/", 0777);
        std::string filename = path + "erase/" + __NAME_SPACE__ + "_erase" + ".diff";
	    std::string filetime = path + "erase/time.diff";
        
        NAMESPACE::vector<int> vec;
        for(int i = 0; i < 10; i++)
            vec.push_back(i + (i *42));
        printContent(filename.c_str(), "ORIGINAL STATE", vec);
        
        /* 📌 ERASE AN ELEM */
        NAMESPACE::vector<int>::iterator it(vec.begin());
        vec.erase(it + 5);
        printContent(filename.c_str(), "ERASE AN ELEM", vec);

        /* 📌 ERASE A RANGE OF ELEM */
        vec.erase(it, it + 4);
        printContent(filename.c_str(), "ERASE A RANGE OF ELEM", vec);

        printTime(filetime.c_str());

        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Modifiers/erase/std_erase.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Modifiers/erase/ft_erase.diff", "r");

			std::cout << "ERASE:                          " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);
		}
    }

    /* SWAP */
    {
        mkdir("./srcs/vector/Modifiers/swap/", 0777);
        std::string filename = path + "swap/" + __NAME_SPACE__ + "_swap" + ".diff";
	    std::string filetime = path + "swap/time.diff";

        NAMESPACE::vector<int> first(10, 42);
        NAMESPACE::vector<int> second(10, 77);

        printContent(filename.c_str(), "FIRST VEC", first);
        printContent(filename.c_str(), "SECOND VEC", second);

        /* 📌 */ first.swap(second);
        printContent(filename.c_str(), "FIRST VEC AFTER THE SWAP", first);
        printContent(filename.c_str(), "SECOND VEC AFTER THE SWAP", second);

        printTime(filetime.c_str());

        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Modifiers/swap/std_swap.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Modifiers/swap/ft_swap.diff", "r");

			std::cout << "SWAP:                           " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);
		}
    }

    /* CLEAR */
    {
        mkdir("./srcs/vector/Modifiers/clear/", 0777);
        std::string filename = path + "clear/" + __NAME_SPACE__ + "_clear" + ".diff";
	    std::string filetime = path + "clear/time.diff";

        NAMESPACE::vector<int> vec(10, 42);

        printContent(filename.c_str(), NULL , vec);

        /* 📌 */ vec.clear();
        printContent(filename.c_str(), "VEC AFTER THE CLEAR", vec);

        printTime(filetime.c_str());

        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Modifiers/clear/std_clear.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Modifiers/clear/ft_clear.diff", "r");

			std::cout << "CLEAR:                          " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);
		}
    }
}