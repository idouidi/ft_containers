/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:34:53 by asimon            #+#    #+#             */
/*   Updated: 2022/12/29 16:08:05 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/ftnspace.hpp"
# include <iostream>
#if STD == 1
	std::string		print_tmp = "STD";
#else
	std::string		print_tmp = "FT";
#endif


int		main(void)
{
	std::cout << print_tmp << std::endl;
	////////////////////////////////////////////////////////////////////////////////
	/*                              VECTOR                                        */
	////////////////////////////////////////////////////////////////////////////////
	
	std::cout << std::endl << YELLOW << "##########VECTOR##########" << RESET << std::endl << std::endl;

	////////////////////////////////////////////////////////////////////////////////
	{	
		std::cout << CYAN << "=========CONSTRUCTOR=========" << RESET << std::endl;
		
		NAMESPACE::vector<int>										tab(1, 40);
		NAMESPACE::vector<int>										tab_bis(2, 10);
		
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << CYAN << "=> Test Default Constructor " << RESET << std::endl << std::endl;
			NAMESPACE::vector< int >			test;

			ft::print(test, "default: ");

			std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << CYAN << "=> Test copy Constructor" << RESET << std::endl << std::endl;
			NAMESPACE::vector< int >			copy(tab);

			ft::print(tab, "original: ");
			std::cout << "sortie" << std::endl;
			ft::print(copy, "copy: ");

			std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << CYAN << "=> Test range constructor" << RESET << std::endl << std::endl;
			
			NAMESPACE::vector< int >		fill(tab.begin() + 1, tab.end());
			
			ft::print(tab, "tab utilise pour fill: ");
			ft::print(fill, "fill by range + 1: ");

			std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
		}
	}	
	////////////////////////////////////////////////////////////////////////////////
	{
		std::cout << CYAN << "=========OPERATOR=========" << RESET << std::endl;
		
			NAMESPACE::vector<int>		std_tab(10,20);
		////////////////////////////////////////////////////////////////////////////////
		{
	
			NAMESPACE::vector<int>		std_tab2 = std_tab;

			ft::print(std_tab,"std_tab: " );		
			std::cout << std::endl;
			ft::print(std_tab2, "std_tab2: " );
	
			std_tab.push_back(100);
			std::cout << std::boolalpha << (std_tab < std_tab2) << std::endl;
			
			for (NAMESPACE::vector<int>::iterator std_it = std_tab2.begin(), std_ite = std_tab2.end();
			std_it != std_ite; std_it++){
				std::cout << *std_it << std::endl;
			}
		}
		////////////////////////////////////////////////////////////////////////////////
	}

	////////////////////////////////////////////////////////////////////////////////
	{
		std::cout << CYAN << "=========INCEPTION=========" << RESET << std::endl;

			NAMESPACE::vector<int>										tab_to_insert(1, 40);
			NAMESPACE::vector<int>										tab_bis_to_insert(2, 10);
			NAMESPACE::vector< NAMESPACE::vector<int> >					tab(4, tab_to_insert);
			NAMESPACE::vector< NAMESPACE::vector<int> >					tab_bis(2, tab_bis_to_insert);


		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << CYAN << "=> Test Default Constructor " << RESET << std::endl << std::endl;
			NAMESPACE::vector< NAMESPACE::vector<int> >			test;

			ft::print(test, "default: ");

			std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << CYAN << "=> Test copy Constructor" << RESET << std::endl << std::endl;
			NAMESPACE::vector< NAMESPACE::vector<int> >			copy(tab);

			ft::print(tab, "original: ");
			ft::print(copy, "copy: ");

			std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << CYAN << "=> Test range constructor" << RESET << std::endl << std::endl;
			
			NAMESPACE::vector< NAMESPACE::vector<int> >		fill(tab.begin() + 1, tab.end());
			
			ft::print(tab, "tab utilise pour fill: ");
			ft::print(fill, "fill by range + 1: ");

			std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << CYAN << "=> Test capacity section:" << RESET << std::endl << std::endl;

			NAMESPACE::vector< NAMESPACE::vector<int> >			test;

			ft::print(tab, "tab: ");
			std::cout << std::boolalpha << "test is empty? [" << GREEN << test.empty() << RESET << "]" << std::endl; 
			std::cout << std::boolalpha << "tab is empty? [" << GREEN << tab.empty() << RESET << "]" << std::endl; 

			std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << CYAN << "=> Test reserve: " << RESET << std::endl << std::endl;

			NAMESPACE::vector< NAMESPACE::vector<int> >			test(tab);

			ft::print(test, "test: ");
			
			std::cout << "resize for 10" << std::endl; 
			test.reserve(10);
			
			ft::print(test, "test after: ");

			std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << CYAN << "=> Test resize:" << RESET << std::endl << std::endl;
			
			NAMESPACE::vector< NAMESPACE::vector<int> >			test(tab);
			
			ft::print(test, "test: ");
			
			std::cout << "resize to 42" << std::endl;
			test.resize(42);

			ft::print(test, "test after: ");			

			std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << CYAN << "=> Test operator[]:" << RESET << std::endl << std::endl;
			NAMESPACE::vector<int>			test;

			for (int i = 0; i < 10; i++)
				test.push_back(i);
				
			ft::print(test, "test: ");
			
			std::cout << "value tab[0]: [" << GREEN << test[0] << RESET << "]" << std::endl;			
			
			std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << CYAN << "=> Test at:" << RESET << std::endl << std::endl;
			NAMESPACE::vector<int>			test;

			for (int i = 0; i < 10; i++)
				test.push_back(i);

			ft::print(test, "test: ");
			
			std::cout << "value tab[2]: [" << GREEN << test.at(2) << RESET << "]" << std::endl;			
			
			std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << CYAN << "=> Test front:" << RESET << std::endl << std::endl;
			NAMESPACE::vector<int>			test;

			for (int i = 0; i < 10; i++)
				test.push_back(i);
				
			ft::print(test, "test: ");
			
			std::cout << "value front: [" << GREEN << test.front() << RESET << "]" << std::endl;			
			
			std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << CYAN << "=> Test back:" << RESET << std::endl << std::endl;
			NAMESPACE::vector<int>			test;

			for (int i = 0; i < 10; i++)
				test.push_back(i);
				
			ft::print(test, "test: ");
			
			std::cout << "value back: [" << GREEN << test.back() << RESET << "]" << std::endl;			
			
			std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		// {
		// 	std::cout << CYAN << "=> Test data:" << RESET << std::endl << std::endl;
		// 	NAMESPACE::vector<int>			test;
		// 	int								*ptr;

		// 	for (int i = 0; i < 10; i++)
		// 		test.push_back(i);
				
		// 	ft::print(test, "test: ");
			
		// 	ptr = test.data();
			
		// 	std::cout << "value ptr[0]: [" << GREEN << ptr[0] << RESET << "]" << std::endl;			
		// 	std::cout << "value ptr[1]: [" << ptr[1] << "]" << std::endl;			
			
		// 	std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
		// }
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << CYAN << "=> Test clear:" << RESET << std::endl << std::endl;
			NAMESPACE::vector<int>			test;

			for (int i = 0; i < 10; i++)
				test.push_back(i);
				
			ft::print(test, "test: ");
			
			test.clear();
			
			ft::print(test, "test: ");
			
			// std::cout << std::endl << "value test.at(1): [" << test.at(1) << "]" << std::endl; 
			// std::cout << std::endl << "value test[1]: [" << test[1] << "]" << std::endl; 
			
			std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << CYAN << "=> Test pop_back:" << RESET << std::endl << std::endl;
			NAMESPACE::vector<int>			test;

			for (int i = 0; i < 10; i++)
				test.push_back(i);
				
			ft::print(test, "test: ");
			
			std::cout << std::endl << "back value: [" << test.back() << "]" << std::endl; 
			test.pop_back();
			std::cout << std::endl << "back value after pop_back: [" << test.back() << "]" << std::endl; 
			
			std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << CYAN << "=> Test swap:" << RESET << std::endl << std::endl;
			NAMESPACE::vector<int>			test;
			NAMESPACE::vector<int>			test_bis;
			NAMESPACE::vector<int>			test_tier;


			for (int i = 0; i < 10; i++)
				test.push_back(i);
			for (int i = 10; i < 24; i++)
				test_bis.push_back(i);
			
			ft::print(test, "test: ");
			ft::print(test_bis, "test_bis: ");
			
			test.swap(test_bis);
			
			ft::print(test, "test after swap : ");
			ft::print(test_bis, "test_bis after swap: ");

			test.swap(test_tier);
			ft::print(test, "test after swap : ");
			ft::print(test_tier, "test_tiers after swap : ");
			
			std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << CYAN << "=> Test erase:" << RESET << std::endl << std::endl;
			NAMESPACE::vector<int>			test;


			for (int i = 0; i < 10; i++)
				test.push_back(i);
			
			ft::print(test, "test: ");
			
			test.erase(test.begin() + 4, test.end());
			
			ft::print(test, "test: ");
			
			std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << CYAN << "=> Test assign:" << RESET << std::endl << std::endl;
			NAMESPACE::vector<int>			test;
			NAMESPACE::vector<int>			test_bis;
			
			for (int i = 0; i < 10; i++)
				test.push_back(i);
			for (int i = 10; i < 24; i++)
				test_bis.push_back(i);
			
			ft::print(test, "test: ");
			ft::print(test_bis, "test_bis: ");
			
			test.assign(test_bis.begin() + 1, test_bis.end());
			ft::print(test, "test 1: ");
			test.assign(8, 42);
			ft::print(test, "test 2: ");
			
			std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << CYAN << "=> Test insert:" << RESET << std::endl << std::endl;
			NAMESPACE::vector<int>			test;
			NAMESPACE::vector<int>			test_bis;
			NAMESPACE::vector<int>			more_test;
			
			for (int i = 0; i < 10; i++)
				test.push_back(0);
			for (int i = 10; i < 24; i++)
				test_bis.push_back(i);
			
			ft::print(test, "test: ");
			ft::print(test_bis, "test_bis: ");
			
			test.insert(test.begin() + 1, test_bis.begin() + 2, test_bis.end());
			
			ft::print(test, "test 1: ");
			
			std::cout << "cap: [" << more_test.capacity() << "]" << std::endl; 
			more_test.insert(more_test.begin(), 9, 42);
			std::cout << "cap: [" << more_test.capacity() << "]" << std::endl;
			ft::print(more_test, "test 2: ");

			
			std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << CYAN << "=> Test insert:" << RESET << std::endl << std::endl;

			NAMESPACE::vector< NAMESPACE::vector<int> >::iterator		it = tab_bis.begin();
			NAMESPACE::vector< NAMESPACE::vector<int> >::iterator		ite = tab_bis.end();

			std::cout << std::endl;
			ft::print(tab, "tab avant insert: ");
			tab.insert(tab.begin(), it, ite);
			ft::print(tab, "tab apres insert: ");

			std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << CYAN << "=> Test swap:" << RESET << std::endl << std::endl;
			/* tab_to_insert | tab_bis_to_insert | tab | tab_bis */
			
			ft::print(tab, "tab: ");
			ft::print(tab_bis, "tab_bis: ");
			std::cout << std::endl;
			tab.swap(tab_bis);
			ft::print(tab, "tab 2eme call: ");
			ft::print(tab, "tab_bis 2eme call: ");

			std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
		}	
		////////////////////////////////////////////////////////////////////////////////
	}
	////////////////////////////////////////////////////////////////////////////////
	{
		std::cout << CYAN << "=========MORE TEST=========" << RESET << std::endl;

		// NAMESPACE::vector<std::string>					test(8);
		// NAMESPACE::vector<std::string>::iterator		it = test.begin();

		// test.push_back("AAAAAA");
		// std::cout << *it << std::endl;
		

		////////////////////////////////////////////////////////////////////////////////
	}
	
	std::cout << YELLOW << "\t\tEND" << RESET << std::endl;	
	return (0);
}
