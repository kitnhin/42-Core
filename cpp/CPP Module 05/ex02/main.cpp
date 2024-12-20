#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    // Successful tests
    cout << '\n' << "successful tests:" << '\n' << endl;
    try
    {
        AForm *shrubby = new ShrubberyCreationForm("home");
        Bureaucrat *bobby = new Bureaucrat("bobby", 5);
        bobby->signForm(*shrubby);
        shrubby->execute(*bobby);
        delete shrubby;
        delete bobby;
        cout << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << endl;
    }
    try
    {
        AForm *boobie = new RobotomyRequestForm("boobeee");
        Bureaucrat *obi = new Bureaucrat("obi", 5);
        obi->signForm(*boobie);
        boobie->execute(*obi);
        delete obi;
        delete boobie;
        cout << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << endl;
    }
    try
    {
        AForm *boobie = new PresidentialPardonForm("boobeee");
        Bureaucrat *obi = new Bureaucrat("obi", 5);
        obi->signForm(*boobie);
        boobie->execute(*obi);
        delete obi;
        delete boobie;
        cout << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << endl;
    }

    //failure sign tests
    cout << "fail sign tests:" << '\n' << endl;

	AForm *boobie = new ShrubberyCreationForm("boobeee");
    Bureaucrat *obi = new Bureaucrat("obi", 150);
    try
    {
        obi->signForm(*boobie);
        boobie->execute(*obi);
        cout << endl;
    }
    catch(const std::exception& e) // too low and form unsigned exception caught
    {
        std::cerr << e.what() << endl;
    }
    delete obi;
    delete boobie;

	boobie = new RobotomyRequestForm("boobeee");
	obi = new Bureaucrat("obi", 70);
    try
    {
        obi->signForm(*boobie);
        boobie->execute(*obi);
        cout << endl;
    }
    catch(const std::exception& e) // too low and form unsigned exception caught
    {
        std::cerr << e.what() << endl;
    }
    delete obi;
    delete boobie;

	boobie = new PresidentialPardonForm("boobeee");
	obi = new Bureaucrat("obi", 150);
	try
    {
        obi->signForm(*boobie);
        boobie->execute(*obi);
        cout << endl;
    }
    catch(const std::exception& e) // too low and form unsigned exception caught
    {
        std::cerr << e.what() << endl;
    }
    delete obi;
    delete boobie;
	
    //fail exec tests
    cout << '\n' << "fail exec tests:" << '\n' << endl;

	boobie = new ShrubberyCreationForm("boobeee");
	obi = new Bureaucrat("obi", 140);
    try
    {
        obi->signForm(*boobie);
        boobie->execute(*obi);
        cout << endl;
    }
    catch(const std::exception& e) // too low exception caught
    {
        std::cerr << e.what() << endl;
    }
	delete obi;
    delete boobie;

	boobie = new RobotomyRequestForm("boobeee");
	obi = new Bureaucrat("obi", 70);
    try
    {
        obi->signForm(*boobie);
        boobie->execute(*obi);
        cout << endl;
    }
    catch(const std::exception& e) // too low exception caught
    {
        std::cerr << e.what() << endl;
    }
    delete obi;
    delete boobie;

	boobie = new PresidentialPardonForm("boobeee");
	obi = new Bureaucrat("obi", 20);
    try
    {
        obi->signForm(*boobie);
        boobie->execute(*obi);
        cout << endl;
    }
    catch(const std::exception& e) // too low exception caught
    {
        std::cerr << e.what() << endl;
    }
    delete obi;
    delete boobie;
}
