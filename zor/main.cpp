#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>


void TableShowcase(std::string name_file, std::string count_file, std::string price_file)
{
	system("cls");
	std::ifstream name, count, price;

	name.open(name_file);
	count.open(count_file);
	price.open(price_file);
	if (!name.is_open() || !count.is_open() || !price.is_open())
	{
		std::cerr << "Error!\n";
	}
	else
	{
		int id = 1;
		std::string data;
		std::cout << "ID" << "\t" << "Название" << "\t" << "Кол-во" << "\t\t" << "Цена" << '\n';
		do
		{
			std::cout << id << "\t";
			name >> data;
			std::cout << data << "\t\t";
			count >> data;
			std::cout << data << "\t\t";
			price >> data;
			std::cout << data << '\n';
		} while (!name.eof() || !count.eof() || !price.eof());
	}

	system("pause");
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char file_choice, choice;
	std::string path_table[3]{ "name.txt", "count.txt", "price.txt" };
	std::ifstream cur_file_read;
	std::ofstream cur_file;
	std::string utof_input;

	while (true)
	{
		do
		{
			system("cls");
			std::cout << "Выберете файл\n";
			std::cout << "(1) Название товара\n(2) Количество товара\n(3) Цена товара\n(4) Вывести данные\n(5) Выход\n";
			std::cin >> file_choice;
		} while (file_choice < '1' || file_choice > '5');
		if (file_choice == '5')
		{
			break;
		}
		else if (file_choice == '4')
		{
			TableShowcase(path_table[0], path_table[1], path_table[2]);
			
		}
		else
		{


			cur_file_read.open(path_table[int(file_choice) - '1']);
			if (!cur_file_read.is_open())
			{
				std::cerr << "Error\n";
				system("pause");
			}
			else
			{
				char eof_check;
				if (cur_file_read >> eof_check)
				{
					cur_file_read.close();
					do
					{
						std::cout << "Перезаписать существующие данные?\n1) Да\n2) Нет\n";
						std::cin >> choice;
					} while (choice < '1' || choice > '2');
					if (choice == '1')
					{
						while (true)
						{
							cur_file.open(path_table[int(file_choice) - 49]);
							if (!cur_file.is_open())
							{
								std::cerr << "Error\n";
								system("pause");
							}
							else
							{
								break;
							}
						}
					}
					else if (choice == '2')
					{

						while (true)
						{
							cur_file.open(path_table[int(file_choice) - 49], std::ofstream::app);
							if (!cur_file.is_open())
							{
								std::cerr << "Error\n";
								system("pause");
							}
							else
							{
								break;
							}
						}
					}
					else
					{
						std::cerr << "Error";
						system("pause");
					}
				}
				else
				{
					cur_file_read.close();
					while (true)
					{
						cur_file.open(path_table[int(file_choice) - '1'], std::ofstream::app);
						if (!cur_file.is_open())
						{
							std::cerr << "Error\n";
							system("pause");
						}
						else
						{
							break;
						}
					}
				}
				while (true)
				{
					system("cls");
					std::cout << "Запись в файл\n";
					std::cin.ignore(32000, '\n');
					std::getline(std::cin, utof_input);
					cur_file << utof_input << '\n';
					do
					{
						std::cout << "Продолжить запись?\n1) Да\n2) Нет\n";
						std::cin >> choice;
					} while (choice < 49 || choice > 50);
					if (choice == '2')
					{
						break;
					}
					else if (choice != '1')
					{
						std::cerr << "Error\n";
						system("pause");
					}
				}
			}
			cur_file.close();
		}
	}

	return 0;
}