/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:21:10 by iziane            #+#    #+#             */
/*   Updated: 2024/12/22 18:21:11 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Summary of Templates and Iterators in C++:

1. **What is a Container?**
	- A container is a data type that stores multiple values (e.g.,
	`std::vector`, `std::list`).
	- Example: A `std::vector<int>` holds a list of integers.

2. **What is an Iterator?**

	- An iterator is a special "pointer" that points to an element in a container.

	- Containers like `std::vector` and `std::list` have their own iterator types,
	e.g., `std::vector<int>::iterator`.

3. **What is a Template?**
	- Templates make functions and classes flexible,
	allowing them to work with different types (e.g.,
	different containers) without rewriting the code.
	- Example: A template function can work with both a `std::vector` and a `std::list`.

4. **How to Search in Containers?**

	- The `std::find` function searches for a value in a container and returns an iterator to the found element.
	- If the value is not found, the iterator points to the end of the container.

5. **How to Implement a Generic Search Function (`easyfind`)?**

	- Write a template function using `typename T` to make it adaptable for different containers.
	- Use `std::find` to search for a value.
	- Throw an exception if the value is not found.

	**Example Code:**
	```cpp
	template <typename T>
	typename T::iterator easyfind(T& container, int value) {
		typename T::iterator it = std::find(container.begin(), container.end(),
				value);
		if (it == container.end()) {
			throw std::runtime_error("Value not found");
		}
		return (it);
	}
*/

#pragma once

// Includes --BEGIN
#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>
// Includes --END

//Exception--BEGIN
class NotFoundException : public std::exception
{
	public:
		virtual const char *what() const throw();
};
//Exception--END


//Function Template
template <typename T> typename T::iterator easyfind(T &container, int needle);

#include "easyfind.tpp"
