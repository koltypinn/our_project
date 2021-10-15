#include "convert.hpp"

bool    boundaries(std::string str)
{
    if (str == "+inf" || str == "-inf" || str =="inf"
        || str == "+inff" || str == "-inff" || str == "inff"
        || str == "nan" || str == "nanf")
        return (true);
    else
        return (false);

}

bool    isNumber(t_status *status)
{
    int         i = 0;
    bool        dot = false;
    std::string arg = status->arg;

    if (boundaries(status->arg))
        return (true);
    if (arg[i] == '-' || arg[i] == '+')
        i++;
    while (arg[i] != '\0')
    {
        if ((arg[i] < '0' || arg[i] > '9'))
        {
            if (arg[i] == 'f' && arg[i + 1] == '\0' && i > 0)
                ;
            else if (arg[i] == '.' && dot)
                return (false);
            else if (arg[i] == '.' && i > 0)
                dot = true;            
            else
                return (false);
        }
        i++;
    }
    return (true);
}

void    checkChar(t_status *status)
{
    status->type = "normal";
    if (status->arg == "nan" || status->arg == "nanf"
        || status->arg == "inf" || status->arg == "+inf" || status->arg == "-inf"
        || status->arg == "inff" || status->arg == "+inff" || status->arg == "-inff")
        status->type = "Impossible";
    else if (status->raw > 256 || status->raw < 0 || errno == ERANGE)
        status->type = "Overflow";
    else if (status->raw < 32 || status->raw > 126)
        status->type = "Non displayable";
}

void    checkInt(t_status *status)
{
    status->type = "normal";
    if (status->arg == "nan" || status->arg == "nanf"
        || status->arg == "inff" || status->arg == "-inff" || status->arg == "+inff")
        status->type = "Impossible";
    else if (status->arg == "inf")
        status->type = "inf";
    else if (status->arg == "+inf")
        status->type = "+inf";
    else if (status->arg == "-inf")
        status->type = "-inf";
    else if (status->raw > std::numeric_limits<int>::max()
        || status->raw < std::numeric_limits<int>::min()
        || errno == ERANGE)
        status->type = "Overflow";
}

void    checkFloat(t_status *status)
{
    status->type = "normal";
    if (status->arg == "nan" || status->arg == "nanf")
        status->type = "nanf";
    else if (status->arg == "inf" || status->arg == "inff")
        status->type = "inff";
    else if (status->arg == "+inf" || status->type == "+inff")
        status->type = "+inff";
    else if (status->arg == "-inf" || status->type == "-inff")
        status->type = "-inff";
    else if (status->raw > std::numeric_limits<float>::max()
        || status->raw < -std::numeric_limits<float>::max()
        || errno == ERANGE)
        status->type = "Overflow";
}

void    checkDouble(t_status *status)
{
    status->type = "normal";
    if (status->arg == "nan" || status->arg == "nanf")
        status->type = "nan";
    else if (status->arg == "inf")
        status->type = "inf";
    else if (status->arg == "+inf" || status->type == "+inff")
        status->type = "+inf";
    else if (status->arg == "-inf" || status->type == "-inff")
        status->type = "-inf";
    else if (errno == ERANGE)
		status->type = "Overflow";
}

void    toChar(t_status *status)
{
    checkChar(status);
    std::cout << "char: ";
    if (status->type != "normal")
        std::cout << status->type;
    else
        std::cout << static_cast<char>(status->raw);
    std::cout << std::endl;
}

void    toInt(t_status *status)
{
    checkInt(status);
    std::cout << "int: ";
    if (status->type != "normal")
        std::cout << status->type;
    else
        std::cout << static_cast<int>(status->raw);
    std::cout << std::endl;
}

void    toFloat(t_status *status)
{
    checkFloat(status);
    std::cout << "float: ";
    if (status->type != "normal")
        std::cout << status->type;
    else
    {
        std::cout << std::fixed << static_cast<float>(status->raw);
        std::cout << "f";
    }
    std::cout << std::endl;
}

void    toDouble(t_status *status)
{
    checkDouble(status);
    std::cout << "double: ";
    if (status->type != "normal")
        std::cout << status->type;
    else
        std::cout << static_cast<double>(status->raw);
    std::cout << std::endl;
}

void    convert(char *arg)
{
    char**      end = NULL;
    t_status    status;

    status.type = "normal";
    status.raw = std::strtod(arg, end);
    status.arg = std::string(arg);
    if (!isNumber(&status))
    {
		std::cout << "Error: Not a number" << std::endl;
		return ;
    }
    std::cout.precision(1);
	toChar(&status);
    toInt(&status);
    toFloat(&status);
    toDouble(&status);
}
