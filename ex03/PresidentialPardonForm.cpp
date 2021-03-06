#include "PresidentialPardonForm.hpp"

const int PresidentialPardonForm::_sign = 25;
const int PresidentialPardonForm::_exec = 5;
const std::string
PresidentialPardonForm::name = "Pardon";

PresidentialPardonForm::PresidentialPardonForm(void) :
	Form("Anonymous", PresidentialPardonForm::name,\
	PresidentialPardonForm::_sign, PresidentialPardonForm::_exec) { }

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	Form(target, PresidentialPardonForm::name,\
	PresidentialPardonForm::_sign, PresidentialPardonForm::_exec) { }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) :
	Form(src.getTarget(), PresidentialPardonForm::name,\
	PresidentialPardonForm::_sign, PresidentialPardonForm::_exec)
{
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(void) { }

PresidentialPardonForm
&PresidentialPardonForm::operator= (const PresidentialPardonForm &obj)
{
	(void)obj;
	return (*this);
}

void
PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	Form::execute(executor);
    std::cout << this->getTarget() << " has been pardoned by Zafod Beebkerox." \
              << std::endl;
}
