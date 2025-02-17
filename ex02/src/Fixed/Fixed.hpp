/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:23:48 by shurtado          #+#    #+#             */
/*   Updated: 2025/02/17 19:31:26 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>


class Fixed
{
	private:
		int					rawBits;
		static const int	fractional = 8;
	public:
		Fixed();
		Fixed(const int intValue);
		Fixed(const float floatValue);
		Fixed(const Fixed &other);
		~Fixed();
		Fixed			&operator=(const Fixed &other);
		int				getRawBits(void) const;
		void			setRawBits(int const rawBits);
		float			toFloat(void) const;
		int				toInt(void) const;
		bool			operator>(const Fixed &other) const;
		bool			operator<(const Fixed &other) const;
		bool			operator>=(const Fixed &other) const;
		bool			operator<=(const Fixed &other) const;
		bool			operator==(const Fixed &other) const;
		bool			operator!=(const Fixed &other) const;
		Fixed			operator+(const Fixed &other) const;
		Fixed			operator-(const Fixed &other) const;
		Fixed			operator*(const Fixed &other) const;
		Fixed			operator/(const Fixed &other) const;
		Fixed			&operator++();
		Fixed			&operator--();
		Fixed			operator++(int);
		Fixed			operator--(int);
		static			Fixed &min(Fixed &a, Fixed &b);
		static			Fixed &max(Fixed &a, Fixed &b);
		static const	Fixed &min(const Fixed &a, const Fixed &b);
		static const	Fixed &max(const Fixed &a, const Fixed &b);

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
