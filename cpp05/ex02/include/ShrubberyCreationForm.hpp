/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:38:51 by jpelline          #+#    #+#             */
/*   Updated: 2025/11/24 17:48:23 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
  private:
	ShrubberyCreationForm();
	const std::string target;

  public:
	ShrubberyCreationForm(const std::string _target);
	ShrubberyCreationForm(const ShrubberyCreationForm &obj) = delete;
	ShrubberyCreationForm operator=(const ShrubberyCreationForm &obj) = delete;
	~ShrubberyCreationForm();
	const std::string get_name() const override;
	void execute() const override;
};
