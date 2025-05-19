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
        bobby->executeForm(*shrubby);
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
        AForm *phoebe = new RobotomyRequestForm("phoebeee");
        Bureaucrat *zani = new Bureaucrat("zani", 5);
        zani->signForm(*phoebe);
        zani->executeForm(*phoebe);
        delete zani;
        delete phoebe;
        cout << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << endl;
    }
    try
    {
        AForm *phoebe = new PresidentialPardonForm("phoebeee");
        Bureaucrat *zani = new Bureaucrat("zani", 5);
        zani->signForm(*phoebe);
		zani->executeForm(*phoebe);
        delete zani;
        delete phoebe;
        cout << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << endl;
    }

    //failure sign tests
    cout << "fail sign tests:" << '\n' << endl;

    AForm *phoebe = new ShrubberyCreationForm("phoebeee");
    Bureaucrat *zani = new Bureaucrat("zani", 150);
    try
    {
        zani->signForm(*phoebe);
        zani->executeForm(*phoebe);
        cout << endl;
    }
    catch(const std::exception& e) // too low and form unsigned exception caught
    {
        std::cerr << e.what() << endl;
    }
    delete zani;
    delete phoebe;

    phoebe = new RobotomyRequestForm("phoebeee");
    zani = new Bureaucrat("zani", 73);
    try
    {
        zani->signForm(*phoebe);
        zani->executeForm(*phoebe);
        cout << endl;
    }
    catch(const std::exception& e) // too low and form unsigned exception caught
    {
        std::cerr << e.what() << endl;
    }
    delete zani;
    delete phoebe;

    phoebe = new PresidentialPardonForm("phoebeee");
    zani = new Bureaucrat("zani", 150);
    try
    {
        zani->signForm(*phoebe);
        zani->executeForm(*phoebe);
        cout << endl;
    }
    catch(const std::exception& e) // too low and form unsigned exception caught
    {
        std::cerr << e.what() << endl;
    }
    delete zani;
    delete phoebe;
    
    //fail exec tests
    cout << '\n' << "fail exec tests:" << '\n' << endl;

    phoebe = new ShrubberyCreationForm("phoebeee");
    zani = new Bureaucrat("zani", 140);
    try
    {
        zani->signForm(*phoebe);
        zani->executeForm(*phoebe);
        cout << endl;
    }
    catch(const std::exception& e) // too low exception caught
    {
        std::cerr << e.what() << endl;
    }
    delete zani;
    delete phoebe;

    phoebe = new RobotomyRequestForm("phoebeee");
    zani = new Bureaucrat("zani", 50);
    try
    {
        zani->signForm(*phoebe);
        zani->executeForm(*phoebe);
        cout << endl;
    }
    catch(const std::exception& e) // too low exception caught
    {
        std::cerr << e.what() << endl;
    }
    delete zani;
    delete phoebe;

    phoebe = new PresidentialPardonForm("phoebeee");
    zani = new Bureaucrat("zani", 20);
    try
    {
        zani->signForm(*phoebe);
        zani->executeForm(*phoebe);
        cout << endl;
    }
    catch(const std::exception& e) // too low exception caught
    {
        std::cerr << e.what() << endl;
    }
    delete zani;
    delete phoebe;
}