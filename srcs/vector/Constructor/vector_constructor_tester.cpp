/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor_tester.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:30:36 by idouidi           #+#    #+#             */
/*   Updated: 2023/01/17 19:28:10 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/ftnspace.hpp"

void vector_constructor_tester()
{
    STD !=  1 ?  std::cout<< YELLOW <<" + CONSTRUCTOR +  " << RESET << std::endl : 0;
	
    std::string path = "./srcs/vector/Constructor/";

	/* DEFAULT CONSTRUCTOR */
	{
		mkdir("./srcs/vector/Constructor/default_constructor", 0777);

		std::string filename = path + "default_constructor/" + __NAME_SPACE__ + "_default_constructor" + ".diff";
		std::string filetime = path + "default_constructor/time.diff";
		
		/* 📌 */ NAMESPACE::vector<int> vec;

		printContent(filename.c_str(), NULL, vec);		
        printTime(filetime.c_str());

		
        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Constructor/default_constructor/std_default_constructor.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Constructor/default_constructor/ft_default_constructor.diff", "r");

			std::cout << "Default Constructor:            " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);                        
		}
	}

	/* FILL CONSTRUCTOR */
	{
		mkdir("./srcs/vector/Constructor/fill_constructor", 0777);

		std::string filename = path + "fill_constructor/" + __NAME_SPACE__ + "_fill_constructor" + ".diff";
		std::string filetime = path + "fill_constructor/time.diff";
		std::string filetime_val = path + "fill_constructor/time_val.diff";
		
		/* 📌 */ NAMESPACE::vector<int> vec(7);
		
		printContent(filename.c_str(), NULL, vec);
		printTime(filetime.c_str());

		/* 📌 */ NAMESPACE::vector<int> vec_with_val(7,42);

		printContent(filename.c_str(), "FILL CONSTRUCTOR WITH A VALUE ",vec_with_val);
		printTime(filetime_val.c_str());

		if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Constructor/fill_constructor/std_fill_constructor.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Constructor/fill_constructor/ft_fill_constructor.diff", "r");

			std::cout << "Fill Constructor:               " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << ((compareTime(filetime.c_str()) && compareTime(filetime_val.c_str())) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);               
		}
	}

    /* COPY CONSTRUCTOR */
	{
        mkdir("./srcs/vector/Constructor/copy_constructor", 0777);

        std::string filename = path + "copy_constructor/" + __NAME_SPACE__ + "_copy_constructor" + ".diff";
        std::string filetime = path + "copy_constructor/time.diff";
        
        /* 📌 */ NAMESPACE::vector<int> vec;

	    for(int i = 0; i < 5; i++)
            vec.push_back(i + (i *10));

	    /* 📌 */ NAMESPACE::vector<int> vec_cpy(vec);

        printContent(filename.c_str(), NULL, vec);
        printContent(filename.c_str(), "COPY VECTOR PART", vec_cpy);
        printTime(filetime.c_str());
        
        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Constructor/copy_constructor/std_copy_constructor.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Constructor/copy_constructor/ft_copy_constructor.diff", "r");

			std::cout << "Copy Constructor:               " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);               
		}
	}
    
    /* RANGE CONSTRUCTOR */
    {
        mkdir("./srcs/vector/Constructor/range_constructor", 0777);

        std::string filename = path + "range_constructor/" + __NAME_SPACE__ + "_range_constructor" + ".diff";
        std::string filetime = path + "range_constructor/time.diff";
        
        /* 📌 */ NAMESPACE::vector<int> vec;

	    for(int i = 0; i < 5; i++)
            vec.push_back(i + (i * 10));
        
	    /* 📌 */  NAMESPACE::vector<int>::iterator it(vec.begin() + 1);
	    /* 📌 */  NAMESPACE::vector<int>::iterator ite(vec.end() - 1);

	    /* 📌 */ NAMESPACE::vector<int> vec_range(it, ite);
        
        printContent(filename.c_str(), NULL, vec);
        printContent(filename.c_str(), "RANGE VECTOR PART", vec_range);
        printTime(filetime.c_str());
        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Constructor/range_constructor/std_range_constructor.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Constructor/range_constructor/ft_range_constructor.diff", "r");

			std::cout << "Range Constructor:              " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);               
		}
    }

    /* ASSIGNING OPERATOR CONSTRUCTOR */
    {
        mkdir("./srcs/vector/Constructor/assigning_operator_constructor", 0777);
        std::string filename = path + "assigning_operator_constructor/" + __NAME_SPACE__ + "_assigning_operator_constructor" + ".diff";
        std::string filetime = path + "assigning_operator_constructor/time.diff";
        
        /* 📌 */ NAMESPACE::vector<int> vec(7,42);
        /* 📌 */ NAMESPACE::vector<int> assign_vec = vec;
        
        printContent(filename.c_str(), NULL, vec);
        printContent(filename.c_str(), "ASSIGNING OPERATOR PART", assign_vec);
        printTime(filetime.c_str());
        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Constructor/assigning_operator_constructor/std_assigning_operator_constructor.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Constructor/assigning_operator_constructor/ft_assigning_operator_constructor.diff", "r");

			std::cout << "Assigning operator Constructor:	" << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);               
		}
    }
}