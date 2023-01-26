/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tester.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:52:37 by idouidi           #+#    #+#             */
/*   Updated: 2023/01/26 17:00:24 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include  "../../../includes/ftnspace.hpp"


void stack_tester()
{
    if (STD != 1)
        std::cout<< "\n\n" << MAGENTA << "        = = =>      STACK      <= = =\n\n"\
        << YELLOW <<" + MEMBER FUNCTION +  " << RESET << std::endl;

    std::fstream os;
    std::string path;

    /* CONSTRCUTOR */
    {
        path = "./srcs/stack/Constructor/";
		mkdir(path.c_str(), 0777);
		std::string filename = path  + __NAME_SPACE__ + "_constructor" + ".diff";
		std::string filetime = path + "time.diff";
		
		/* 📌  */
        NAMESPACE::stack<int> stk;
		printCapacity(filename.c_str(), "EMPTY CONSTRCUCTOR", stk);
    
        for (int i = 0; i < 5; i++)
            stk.push(i);
		printCapacity(filename.c_str(), "FILL CONSTRCUCTOR", stk);

        printTime(filetime.c_str());
		
        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/stack/Constructor/std_constructor.diff", "r");
			FILE *f2 = std::fopen("./srcs/stack/Constructor/ft_constructor.diff", "r");

			std::cout << "Constructor:                    " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);
		}
    }

   /* EMPTY */ 
   {
        path = "./srcs/stack/Empty/";
		mkdir(path.c_str(), 0777);
		std::string filename = path  + __NAME_SPACE__ + "_empty" + ".diff";
		std::string filetime = path + "time.diff";

        os.open(filename.c_str(), std::fstream::in | std::fstream::out |  std::ios_base::app);
        if (!os.is_open()) 
        {
            std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
            exit(EXIT_FAILURE);
        }
		
        /* 📌 FILL */
        std::stack<int> first;

        /* 📌 NOT EMPTY */
        std::stack<int> second;
        for (int i = 0; i < 5; i++)
            second.push(i);

        os << "Is the first stack is empty ? " << (first.empty() ? "YES" : "NO") << std::endl;
        os << "Is the second stack is empty ? " << (second.empty() ? "YES" : "NO") << std::endl;

        printTime(filetime.c_str());
		
        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/stack/Empty/std_empty.diff", "r");
			FILE *f2 = std::fopen("./srcs/stack/Empty/ft_empty.diff", "r");

			std::cout << "Empty:                          " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);
		}
        os.close();
   }
    
    /* SIZE */ 
   {
        path = "./srcs/stack/Size/";
		mkdir(path.c_str(), 0777);
		std::string filename = path  + __NAME_SPACE__ + "_size" + ".diff";
		std::string filetime = path + "time.diff";

        os.open(filename.c_str(), std::fstream::in | std::fstream::out |  std::ios_base::app);
        if (!os.is_open()) 
        {
            std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
            exit(EXIT_FAILURE);
        }

        NAMESPACE::stack<int> stk;
    
        for (int i = 0; i < 5; i++)
            stk.push(i);


        while (!stk.empty())
        {
            os << "The size of the stack is = " << stk.size() << std::endl;
            stk.pop();
        }
        os << "The size of the stack is = " << stk.size() << std::endl;

        printTime(filetime.c_str());
		
        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/stack/Empty/std_empty.diff", "r");
			FILE *f2 = std::fopen("./srcs/stack/Empty/ft_empty.diff", "r");

			std::cout << "Size:                           " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);
		}
        os.close();
   }

    /* TOP */
    {
        path = "./srcs/stack/Top/";
		mkdir(path.c_str(), 0777);
		std::string filename = path  + __NAME_SPACE__ + "_top" + ".diff";
		std::string filetime = path + "time.diff";

        os.open(filename.c_str(), std::fstream::in | std::fstream::out |  std::ios_base::app);
        if (!os.is_open()) 
        {
            std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
            exit(EXIT_FAILURE);
        }

        NAMESPACE::stack<int> stk;

        stk.push(10);
        stk.push(20);
        /* 📌 */ stk.top() -= 5;

        os << "The value of the top is : [" << stk.top() << "]" << std::endl;

        printTime(filetime.c_str());

        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/stack/Empty/std_empty.diff", "r");
			FILE *f2 = std::fopen("./srcs/stack/Empty/ft_empty.diff", "r");

			std::cout << "Top:                            " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);
		}
        os.close();
    }

    /* PUSH */
    {
        path = "./srcs/stack/Push/";
		mkdir(path.c_str(), 0777);
		std::string filename = path  + __NAME_SPACE__ + "_push" + ".diff";
		std::string filetime = path + "time.diff";

        os.open(filename.c_str(), std::fstream::in | std::fstream::out |  std::ios_base::app);
        if (!os.is_open()) 
        {
            std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
            exit(EXIT_FAILURE);
        }

        NAMESPACE::stack<int> stk;

        for (int i = 0; i < 5; i++)
        {
            /* 📌 */ stk.push(i);
            os << "The value to the push is [" << stk.top() << "]" << std::endl;
        }

        printTime(filetime.c_str());

        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/stack/Empty/std_empty.diff", "r");
			FILE *f2 = std::fopen("./srcs/stack/Empty/ft_empty.diff", "r");

			std::cout << "Push:                           " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);
		}
        os.close();
    }

    /* POP*/
    {
        path = "./srcs/stack/Pop/";
		mkdir(path.c_str(), 0777);
		std::string filename = path  + __NAME_SPACE__ + "_pop" + ".diff";
		std::string filetime = path + "time.diff";

        os.open(filename.c_str(), std::fstream::in | std::fstream::out |  std::ios_base::app);
        if (!os.is_open()) 
        {
            std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
            exit(EXIT_FAILURE);
        }

        NAMESPACE::stack<int> stk;

        for (int i = 0; i < 5; i++)
            stk.push(i);
        
        os << "Popping out elements..." << std::endl;
         while (!stk.empty())
        {
            os << ' ' << stk.top() << std::endl;;
            /* 📌 */ stk.pop();
        }

        printTime(filetime.c_str());

        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/stack/Pop/std_pop.diff", "r");
			FILE *f2 = std::fopen("./srcs/stack/Pop/ft_pop.diff", "r");

			std::cout << "Pop:                            " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);
		}
        os.close();     
    }
}