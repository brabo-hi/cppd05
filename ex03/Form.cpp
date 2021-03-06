#include "Form.hpp"

Form::Form(void) :
	_signed(false),
	_grade_to_sign(1),
	_grade_to_execute(1),
	_name("undefined") { }

Form::Form(const Form &src) :
	_signed(src._signed),
	_grade_to_sign(src._grade_to_sign),
	_grade_to_execute(src._grade_to_execute),
	_name(src._name),
	_target(src._target)
{
	*this = src;
}

Form::Form(std::string target, std::string name,\
		int grade_to_sign, int grade_to_execute) :
	_signed(false),
	_grade_to_sign(grade_to_sign),
	_grade_to_execute(grade_to_execute),
	_name(name),
	_target(target)
{
	if (this->_grade_to_sign < MIN_GRADE || this->_grade_to_execute < MIN_GRADE)
		throw Form::GradeTooHighException();
	if (this->_grade_to_sign > MAX_GRADE || this->_grade_to_execute > MAX_GRADE)
		throw Form::GradeTooLowException();
}

Form::~Form(void) { }

Form
&Form::operator= (const Form &obj)
{
	this->_signed = obj._signed;
	return (*this);
}

void
Form::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() > this->_grade_to_sign)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

bool
Form::getSigned(void) const
{
	return (this->_signed);
}

int
Form::getGradeToSign(void) const
{
	return (this->_grade_to_sign);
}

int
Form::getGradeToExecute(void) const
{
	return (this->_grade_to_execute);
}

std::string
Form::getName(void) const
{
	return (this->_name);
}

std::string
Form::getTarget(void) const
{
	return (this->_target);
}

void
Form::execute(const Bureaucrat& executor) const
{
	if (!_signed)
	{
		throw Form::NotSignedException();
	}
	else if (executor.getGrade() > _grade_to_execute)
	{
		throw Form::GradeTooLowException();
	}
}

std::ostream
&operator<< (std::ostream &out, const Form &obj)
{
	out << "Form Details:" << std::endl
			<< "Name: " << obj.getName() << std::endl
			<< "Target: " << obj.getTarget() << std::endl
			<< "Signing Grade Requirement: " << obj.getGradeToSign() << std::endl
			<< "Execution Grade Requirement: " << obj.getGradeToExecute() << std::endl;
	if(obj.getSigned())
			out << "Form has been signed." << std::endl;
	else
			out << "Form has not been signed yet." << std::endl;
	return (out);
}


Form::
GradeTooHighException::GradeTooHighException(void) {}

Form::
GradeTooHighException::GradeTooHighException(const GradeTooHighException &src)
{
	*this = src;
}

Form::
GradeTooHighException::~GradeTooHighException(void) throw() {}

Form::GradeTooHighException
&Form::GradeTooHighException::operator= (const GradeTooHighException &rhs)
{
	(void)rhs;
	return (*this);
}

const char
*Form::GradeTooHighException::message = "Bureaucrat's grade is too high.";

const char
*Form::
GradeTooHighException::what() const throw()
{
	return (Form::GradeTooHighException::message);
}

const char
*Form::GradeTooLowException::message = "Bureaucrat's grade is too low.";

Form::
GradeTooLowException::GradeTooLowException(void) {}

Form::
GradeTooLowException::GradeTooLowException(const GradeTooLowException &src)
{
	*this = src;
}

Form::
GradeTooLowException::~GradeTooLowException(void) throw() {}

Form::GradeTooLowException
&Form::GradeTooLowException::operator= (const GradeTooLowException &rhs)
{
    (void)rhs;
    return (*this);
}

const char
*Form::
GradeTooLowException::what() const throw()
{
	return (Form::GradeTooLowException::message);
}

const char
*Form::NotSignedException::message =\
		"Form cannot be executed as it was not signed yet.";

Form::
NotSignedException::NotSignedException(void) {}

Form::
NotSignedException::NotSignedException(const NotSignedException &src)
{
	*this = src;
}

Form::
NotSignedException::~NotSignedException(void) throw() {}

Form::NotSignedException
&Form::NotSignedException::operator= (const NotSignedException &rhs)
{
    (void)rhs;
    return (*this);
}

const char
*Form::
NotSignedException::what() const throw()
{
	return (Form::NotSignedException::message);
}
