/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity_tester.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:55:23 by idouidi           #+#    #+#             */
/*   Updated: 2023/01/17 19:01:13 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/ftnspace.hpp"

void capacity_tester()
{
    STD !=  1 ?  std::cout<< YELLOW <<" + CAPACITY +  " << RESET << std::endl : 0;

    std::string path = "./srcs/vector/Capacity/";
    std::fstream os;

    /* SIZE */
    {
        mkdir("./srcs/vector/Capacity/size", 0777);
        std::string filename = path + "size/" + __NAME_SPACE__ + "_size" + ".diff";
		std::string filetime = path + "size/time.diff";
        
        os.open(filename.c_str(), std::fstream::in | std::fstream::out |  std::ios_base::app);
        if (!os.is_open()) 
        {
            std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
            exit(EXIT_FAILURE);
        }

        NAMESPACE::vector<int> vec;

        os << "PUSH ELEM:" << std::endl;
	    for(int i = 0; i < 5; i++)
        {
            vec.push_back(i + (i *10));
            /* 📌 */ os << " SIZE = " << vec.size() << std::endl; 
        }
        os << "\nPOP ELEM:" << std::endl;
        for (int i = 0; i < 5; i++)
        {
            vec.pop_back();
            /* 📌 */ os << " SIZE = " << vec.size() << std::endl;
        }

        printTime(filetime.c_str());

        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Capacity/size/std_size.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Capacity/size/ft_size.diff", "r");

			std::cout << "Size:                           " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);               
		}
        os.close();
    }

    /* MAX_SIZE */
    {
        mkdir("./srcs/vector/Capacity/max_size", 0777);
        std::string filename = path + "max_size/" + __NAME_SPACE__ + "_max_size" + ".diff";
		std::string filetime = path + "max_size/time.diff";
        
        os.open(filename.c_str(), std::fstream::in | std::fstream::out |  std::ios_base::app);
        if (!os.is_open()) 
        {
            std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
            exit(EXIT_FAILURE);
        }

        NAMESPACE::vector<int> vec(100, 42);
        NAMESPACE::vector< NAMESPACE::vector<int> >	vec_of_vec(4, vec);
        
        os << "INT VECTOR" << std::endl;
        /* 📌 */ os << "MAXSIZE = " << vec.max_size() << std::endl;

        os << "\nVECTOR OF INT VECTOR" << std::endl;
        for (size_t i = 0; i < vec_of_vec.size(); i++)
        /* 📌 */    os << "VEC[" << i << "]" << "  MAXSIZE =  " << vec_of_vec[i].max_size() << std::endl;
        
        printTime(filetime.c_str());
        
        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Capacity/max_size/std_max_size.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Capacity/max_size/ft_max_size.diff", "r");

			std::cout << "Max Size:                       " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);               
		}
        os.close();
    }

    /* RESIZE */
    {
        mkdir("./srcs/vector/Capacity/resize", 0777);
        std::string filename = path + "resize/" + __NAME_SPACE__ + "_resize" + ".diff";
		std::string filetime = path + "resize/time.diff";
        
        NAMESPACE::vector<int> vec;

	    for(int i = 0; i < 4; i++)
            vec.push_back(i + (i *10));

        printContent(filename.c_str(), "ORIGINAL STATE:", vec);

        /* 📌 */ vec.resize(2);
        printContent(filename.c_str(), "RESIZE WITH N < SIZE() ", vec);

        /* 📌 */ vec.resize(10);
        printContent(filename.c_str(), "RESIZE WITH N > SIZE() ", vec);

        printTime(filetime.c_str());

        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Capacity/resize/std_resize.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Capacity/resize/ft_resize.diff", "r");

			std::cout << "Resize:                         " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);
		}
    }

    /* CAPACITY */
    {
        mkdir("./srcs/vector/Capacity/capacity", 0777);
        std::string filename = path + "capacity/" + __NAME_SPACE__ + "_capacity" + ".diff";
		std::string filetime = path + "capacity/time.diff";

        os.open(filename.c_str(), std::fstream::in | std::fstream::out |  std::ios_base::app);
        if (!os.is_open()) 
        {
            std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
            exit(EXIT_FAILURE);
        }

        NAMESPACE::vector<int> vec;

        os << "#    #   #   #   #   #   #   #   #   #   #   #   #\n"<<std::endl; 
        os << "INT VECTOR:\n" << std::endl;
        for (int i  = 0; i < 5; i++)
        {
            vec.push_back(i);
            /* 📌 */ os << "CAPACITY = " << vec.capacity() << " | SIZE = " << vec.size()<< std::endl;
        }
        os << "#    #   #   #   #   #   #   #   #   #   #   #   #"<<std::endl;

        NAMESPACE::vector< NAMESPACE::vector<int> >	vec_of_vec(4, vec);
        

        os << "\nVECTOR OF INT VECTORS:\n" << std::endl;
        for (size_t i = 0; i < vec_of_vec.size(); i++)
        /* 📌 */    os << "VEC[" << i << "]" << "  CAPACITY =  " << vec_of_vec[i].capacity() << std::endl;
         os << "#    #   #   #   #   #   #   #   #   #   #   #   #"<<std::endl;


        printTime(filetime.c_str());

        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Capacity/capacity/std_capacity.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Capacity/capacity/ft_capacity.diff", "r");

			std::cout << "Capacity:                       " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);
		}
        os.close();
    }

    /* RESERVE */
    {
        mkdir("./srcs/vector/Capacity/reserve", 0777);
        std::string filename = path + "reserve/" + __NAME_SPACE__ + "_reserve" + ".diff";
		std::string filetime = path + "reserve/time.diff";
        
        os.open(filename.c_str(), std::fstream::in | std::fstream::out |  std::ios_base::app);
        if (!os.is_open()) 
        {
            std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
            exit(EXIT_FAILURE);
        }

        NAMESPACE::vector<int> vec(4, 42);
        os << "\n               " <<  "N < CAPACITY" << std::endl;
        os << "#    #   #   #   #   #   #   #   #   #   #   #   #"<<std::endl; 
        os << "BEFORE RESERVE CALLED, CAPACITY  = [" << vec.capacity() << "]" << std::endl;
        /* 📌 */ vec.reserve(2);
        os << "AFTER RESERE CALLED, CAPACITY    = ["<< vec.capacity() << "]" <<  std::endl;
        os << "#    #   #   #   #   #   #   #   #   #   #   #   #"<<std::endl;

        NAMESPACE::vector<int> vec_bis(5, 42);

        os << "\n               " <<  "N > CAPACITY" << std::endl;
        os << "#    #   #   #   #   #   #   #   #   #   #   #   #"<<std::endl; 
        os << "BEFORE RESERVE CALLED, CAPACITY  = [" << vec_bis.capacity() << "]" << std::endl;
        /* 📌 */ vec_bis.reserve(11);
        os << "AFTER RESERE CALLED, CAPACITY    = ["<< vec_bis.capacity() << "]" <<  std::endl;
        os << "#    #   #   #   #   #   #   #   #   #   #   #   #"<<std::endl;
        
        printTime(filetime.c_str());

        if (STD != 1)
		{
			FILE *f1 = std::fopen("./srcs/vector/Capacity/reserve/std_reserve.diff", "r");
			FILE *f2 = std::fopen("./srcs/vector/Capacity/reserve/ft_reserve.diff", "r");

			std::cout << "Reserve:                        " << (compareFile(f1, f2) ? OK : KO);
			std::cout << " TIME: " << (compareTime(filetime.c_str()) ? OK : KO) << std::endl;
			std::fclose(f1);
			std::fclose(f2);
		}
        os.close();
    }

    /*EMPTY */
    {
          mkdir("./srcs/vector/Capacity/reserve", 0777);
    }
    
}