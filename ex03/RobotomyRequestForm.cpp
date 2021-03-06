#include "RobotomyRequestForm.hpp"

const int RobotomyRequestForm::_sign = 75;
const int RobotomyRequestForm::_exec = 45;
const std::string
RobotomyRequestForm::name = "Robotomy";

RobotomyRequestForm::RobotomyRequestForm(void) :
	Form("Anonymous", RobotomyRequestForm::name,\
	RobotomyRequestForm::_sign, RobotomyRequestForm::_exec) { }

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	Form(target, RobotomyRequestForm::name, \
	RobotomyRequestForm::_sign, RobotomyRequestForm::_exec) { }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :
	Form(src.getTarget(), RobotomyRequestForm::name,\
	RobotomyRequestForm::_sign, RobotomyRequestForm::_exec)
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void) { }

RobotomyRequestForm
&RobotomyRequestForm::operator= (const RobotomyRequestForm &obj)
{
	(void)obj;
	return (*this);
}

void
RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	Form::execute(executor);
	if (rand() & 1)
	{
		std::cout << "BZZZZZZZZZZ..."\
				<< getTarget() \
				<< " has been robotomized successfully !" << std::endl;
	}
	else
	{
		std::cout << "The " << getTarget() << "robotomization failed !" \
				<< std::endl;
	}
}
