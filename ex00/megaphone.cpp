#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    int i;
    int j;

    j = 1;

    if (ac > 1)
    {

        while (j < ac)
        {
            i = 0;
            while (av[j][i])
            {
                std::cout << (char)std::toupper(av[j][i]);
                i++;    
            }
            if (j < ac - 1)
                std::cout << " ";
            j++;
        }
    }
    else 
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return (0);
}