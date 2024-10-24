#include "phonebook.hpp"

void	search_contact(PhoneBook *pb)
{
	for (std::size_t i = 0; i < pb->amount_contacts; i++)
	{
		pb->print_data(i);
	}
}
